#include "mtk/driver/window_driver.h"

#define UNICODE

#include <stdexcept>
#include <Windows.h>
#include <iomanip>
#include <iostream>

#include "mtk/window.h"
#include "win32.h"
#include "mtk/driver/graphics_driver.h"
#include "../gdiplus/gdiplus_graphics_driver.h"

// test 
#include <gdiplus.h>
#include <mtk/color.h>

namespace mtk {

    LRESULT CALLBACK window_procedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        window_driver* d = reinterpret_cast<window_driver*>(::GetWindowLongPtrW(hwnd, GWLP_USERDATA));

        if (d != nullptr)
        {
            window* w = d->window();
            std::cout << get_msg_str(msg) << " -> " << w->get_name() << "\n";

            switch (msg)
            {


                case WM_CLOSE:
                {
                    ::PostQuitMessage(0);
                }   break;


                case WM_DPICHANGED:
                {
                    int dpi = HIWORD(wparam);

                    LPRECT prc = reinterpret_cast<LPRECT>(lparam);
                    ::MoveWindow(hwnd, prc->left, prc->right, prc->right - prc->left, prc->bottom - prc->top, TRUE);

                    d->set_scale(static_cast<float>(dpi) / USER_DEFAULT_SCREEN_DPI);

                    RECT rc = {};
                    ::GetClientRect(hwnd, &rc);
                    w->move({ d->unscale(rc.left), d->unscale(rc.right) });
                    w->resize({ d->unscale(rc.right - rc.left), d->unscale(rc.bottom - rc.top) });


                }
                break;


                case WM_SIZE:
                {
                    w->resize({ d->unscale(LOWORD(lparam)), d->unscale(HIWORD(lparam)) });
                }
                break;


                case WM_PAINT:
                {
                    PAINTSTRUCT ps = { };
                    HDC hdc = ::BeginPaint(hwnd, &ps);

                    gdiplus_graphics_driver ggd(d, hdc);
                    ggd.begin();

                    canvas cv(w, &ggd);
                    cv.fill(colors::white);
                    w->draw(cv);

                    ::EndPaint(hwnd, &ps);
                }
                return 0;

            }
        }

        return ::DefWindowProcW(hwnd, msg, wparam, lparam);
    }


    struct init_window_class {
        init_window_class()
        {
            WNDCLASSEXW wc = { };
            wc.cbSize = sizeof(wc);
            wc.hInstance = ::GetModuleHandleW(nullptr);

            wc.lpszClassName = name;

            wc.hbrBackground = nullptr;
            //wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

            wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
            wc.lpfnWndProc = window_procedure;
            wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

            if (::RegisterClassExW(&wc) == 0)
            {
                throw std::runtime_error("init_window_class::init_window_class -> ::RegisterClassExW failed");
            }
        }

        const wchar_t* name = L"mtkWindow";
    };



    struct window_driver::context {

        HWND handle = nullptr;

        float scale = 1.0;

    };


    window_driver::window_driver() : m_window(nullptr),  m_ctx(std::make_unique<window_driver::context>()) {};

    window_driver::~window_driver() = default;


    void window_driver::create(mtk::window* w)
    {
        static init_window_class wc;

        m_window = w;

        m_scale = (static_cast<float>(::GetDpiForSystem()) / USER_DEFAULT_SCREEN_DPI);


        m_ctx->handle = ::CreateWindowExW(0,
                                          wc.name, utf8_to_wchar(w->get_name()).c_str(), WS_OVERLAPPEDWINDOW,
                                          scale(w->position().x), scale(w->position().y),
                                          scale(w->size().width), scale(w->size().height),
                                          nullptr, nullptr, ::GetModuleHandleW(nullptr), nullptr);

        if (m_ctx->handle == nullptr)
        {
            throw std::runtime_error("window_driver::create -> CreateWindowExW returned an invalid window handle");
        }


        ::SetWindowLongPtrW(m_ctx->handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

        ::ShowWindow(m_ctx->handle, SW_SHOW);
    }


    void window_driver::resize(const size& sz)
    {
        ::SetWindowPos(m_ctx->handle, 0, 0, 0, sz.width, sz.height, SWP_NOMOVE | SWP_NOZORDER);
    }

    mtk::window* window_driver::window() const { return m_window; };





}