#pragma once

#include <inttypes.h>

namespace mtk {




    struct color {

        constexpr color() = default;
        constexpr color(uint8_t r, uint8_t g, uint8_t b) : red(r), green(g), blue(b), alpha(UINT8_MAX) {};
        constexpr color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : red(r), green(g), blue(b), alpha(a) {};

        uint8_t red = 0;
        uint8_t green = 0;
        uint8_t blue = 0;
        uint8_t alpha = UINT8_MAX;
    };


    namespace colors {

        constexpr color black(0, 0, 0);
        constexpr color gray(128, 128, 128);
        constexpr color white(255, 255, 255);

    }



}