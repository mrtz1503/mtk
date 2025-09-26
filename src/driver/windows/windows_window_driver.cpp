#include "mtk/driver/window_driver.h"

#define UNICODE

#include <stdexcept>
#include <Windows.h>
#include <iomanip>
#include <iostream>

#include "mtk/window.h"
#include "win32.h"
#include "mtk/driver/graphics_driver.h"

// test 
#include <d2d1.h>

namespace mtk {

    LRESULT CALLBACK window_procedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        window* w = reinterpret_cast<window*>(::GetWindowLongPtrW(hwnd, GWLP_USERDATA));

        if (w != nullptr)
        {
            std::cout << get_msg_str(msg) << " -> " << w->get_name() << "\n";
        }

        if (w != nullptr)
        {
            switch (msg)
            {
                case WM_CLOSE:
                {
                    ::PostQuitMessage(0);
                }   break;


                case WM_DPICHANGED:
                {
                    int dpi = HIWORD(wparam);
                    w->set_scale(static_cast<float>(dpi) / USER_DEFAULT_SCREEN_DPI);
                }
                break;

                case WM_PAINT:
                {
                    
                        graphics_driver drv(::GetDC(hwnd));
                        drv.color(colors::black);


                        drv.line(10, 10, 10, 200);

                }
                break;


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

    };


    window_driver::window_driver() : m_ctx(std::make_unique<window_driver::context>()) {};

    window_driver::~window_driver() = default;


    void window_driver::create(window* w)
    {
        static init_window_class wc;

        w->set_scale(static_cast<float>(::GetDpiForSystem()) / USER_DEFAULT_SCREEN_DPI);

        m_ctx->handle = ::CreateWindowExW(0,
                                          wc.name, utf8_to_wchar(w->get_name()).c_str(), WS_OVERLAPPEDWINDOW,
                                          w->scale(w->position().x), w->scale(w->position().y),
                                          w->scale(w->size().width), w->scale(w->size().height),
                                          nullptr, nullptr, ::GetModuleHandleW(nullptr), nullptr);

        if (m_ctx->handle == nullptr)
        {
            throw std::runtime_error("window_driver::create -> CreateWindowExW returned an invalid window handle");
        }



        ::SetWindowLongPtrW(m_ctx->handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(w));

        ::ShowWindow(m_ctx->handle, SW_SHOW);
    }







}