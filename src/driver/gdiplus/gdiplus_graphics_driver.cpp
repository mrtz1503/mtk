#pragma once

#include "gdiplus_graphics_driver.h"

#include "mtk/driver/window_driver.h"

namespace mtk {


    void gdiplus_graphics_driver::begin()
    {
        m_graphics = std::make_unique<Gdiplus::Graphics>(m_hdc);
    }

    void gdiplus_graphics_driver::color(const mtk::color& c)
    {

        m_color = Gdiplus::Color(c.alpha, c.red, c.green, c.blue);

    };



    void gdiplus_graphics_driver::line(int x1, int y1, int x2, int y2)
    {

        Gdiplus::Graphics g(m_hdc);

        Gdiplus::Pen pen(Gdiplus::Color(255, 0, 0, 0));
        pen.SetWidth(10);
        g.DrawLine(&pen, x1, y1, x2, y2);





    };

    void gdiplus_graphics_driver::rect(int x, int y, int width, int height)
    {
        Gdiplus::Pen pen(m_color);
        m_graphics->DrawRectangle(&pen, m_drv->scale(x), m_drv->scale(y), 
                                  m_drv->scale(width), m_drv->scale(height));
    }


    void gdiplus_graphics_driver::rect_fill(int x, int y, int width, int height)
    {
        Gdiplus::SolidBrush brush(m_color);
        m_graphics->FillRectangle(&brush, m_drv->scale(x), m_drv->scale(y), m_drv->scale(width), m_drv->scale(height));
    };

    //graphics_driver::graphics_driver(void* context) : m_ctx(std::make_unique<graphics_driver::ctx>())
    //{
    //    m_ctx->hdc = static_cast<HDC>(context);
    //};
    //graphics_driver::~graphics_driver() = default;


    //void graphics_driver::color(mtk::color c) { m_color = c; }

    //void graphics_driver::line(int x1, int y1, int x2, int y2)
    //{
    //    HDC hdc = m_ctx->hdc;

    //    HPEN hPenOld;
    //    HPEN hLinePen;
    //    COLORREF qLineColor;
    //    qLineColor = RGB(m_color.red, m_color.green, m_color.blue);
    //    hLinePen = ::CreatePen(PS_SOLID, 1, qLineColor);
    //    hPenOld = (HPEN)::SelectObject(hdc, hLinePen);

    //    MoveToEx(hdc, x1, y1, NULL);
    //    LineTo(hdc, x2, y2);

    //    SelectObject(hdc, hPenOld);
    //    DeleteObject(hLinePen);


    //}



}