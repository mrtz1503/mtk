#pragma once

#include "mtk/driver/graphics_driver.h"
#include "mtk/color.h"

#include <Windows.h>
#include <gdiplus.h>


namespace mtk {

    class window_driver;

    struct init_gdiplus {

        init_gdiplus()
        {
            Gdiplus::GdiplusStartupInput gdiplusStartupInput;
            Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
        }

        ~init_gdiplus()
        {            
            Gdiplus::GdiplusShutdown(m_gdiplusToken);
        }

    private:
        ULONG_PTR m_gdiplusToken = 0;

    };

    class gdiplus_graphics_driver : public graphics_driver {
    public:

        gdiplus_graphics_driver(window_driver *driver, HDC hdc) : m_drv(driver), m_hdc(hdc)
        {
            static  init_gdiplus init;
        };


        virtual void begin() override;

        virtual void color(const mtk::color& c) override;

        virtual void line(int x1, int y1, int x2, int y2) override;
        virtual void rect(int x, int y, int width, int height) override;
        virtual void rect_fill(int x, int y, int width, int height) override;



    private:

        window_driver *m_drv;

        Gdiplus::Color m_color;
        std::unique_ptr<Gdiplus::Graphics> m_graphics;

        HDC m_hdc = nullptr;

    };


}