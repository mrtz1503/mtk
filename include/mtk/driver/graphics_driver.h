#pragma once

#include "mtk/color.h"
#include <memory>

namespace mtk {

    class graphics_driver {
    public:

        graphics_driver(void* context);
        ~graphics_driver();

        void color(mtk::color c);

        void line(int x1, int y1, int x2, int y2);



    private:

        struct ctx;
        std::unique_ptr<graphics_driver::ctx> m_ctx;

        mtk::color m_color;

    };



}