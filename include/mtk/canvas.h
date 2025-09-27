#pragma once

#include "mtk/driver/graphics_driver.h"

namespace mtk {
    
    class widget;

    class canvas {
    public:

        canvas(widget *w, graphics_driver* gd) : m_widget(w), m_drv(gd) {};


        void dot(int x, int y);
        void line(int x1, int y1, int x2, int y2);
        void rectangle(int x1, int y1, int x2, int y2);

        void fill(const color& c);

    private:


        widget* m_widget;

        graphics_driver* m_drv;

    };


}