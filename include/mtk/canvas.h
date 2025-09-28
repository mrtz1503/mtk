#pragma once



#include "mtk/size.h"
#include "mtk/point.h"
#include "mtk/color.h"


namespace mtk {
    
    class widget;
    class graphics_driver;

    class canvas {
    public:

        canvas(widget* w, graphics_driver* gd);


        void dot(int x, int y);
        void line(int x1, int y1, int x2, int y2);
        void rect(int x1, int y1, int width, int height);

        void fill(const mtk::color& c);


        mtk::size size();

        graphics_driver* driver();

    private:
        point m_offpos;

        widget* m_widget;
        graphics_driver* m_drv;

    };


}