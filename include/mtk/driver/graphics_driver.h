#pragma once

#include "mtk/color.h"
#include <memory>

namespace mtk {

    // abstract base class
    class graphics_driver {
    public:

        virtual void begin() = 0;
        
        // lines
        virtual void line(int x1, int y1, int x2, int y2) = 0;
        
        // rectangels
        virtual void rect(int x, int y, int width, int height) = 0;
        virtual void rect_fill(int x, int y, int width, int height) = 0;
        

        // color stuff
        virtual void color(const color& c) = 0;



    private:


    };



}