#pragma once

#include "mtk/driver/graphics_driver.h"
#include "mtk/window.h"

#include <memory>

#include <Windows.h>

namespace mtk {

    struct graphics_driver::ctx {

        HDC hdc = nullptr;

    };

    graphics_driver::graphics_driver(void* context) : m_ctx(std::make_unique<graphics_driver::ctx>())
    {
        m_ctx->hdc = static_cast<HDC>(context);
    };
    graphics_driver::~graphics_driver() = default;


    void graphics_driver::color(mtk::color c) { m_color = c; }

    void graphics_driver::line(int x1, int y1, int x2, int y2)
    {
        HDC hdc = m_ctx->hdc;

        HPEN hPenOld;
        HPEN hLinePen;
        COLORREF qLineColor;
        qLineColor = RGB(m_color.red, m_color.green, m_color.blue);
        hLinePen = ::CreatePen(PS_SOLID, 1, qLineColor);
        hPenOld = (HPEN)::SelectObject(hdc, hLinePen);

        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);

        SelectObject(hdc, hPenOld);
        DeleteObject(hLinePen);


    }



}