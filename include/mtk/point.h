#pragma once

namespace mtk {


    struct point {

        point() = default;
        point(int x, int y) : x(x), y(y){};

        point operator+ (const point& first) const
        {
            return point(x + first.x, y + first.y);
        }

        point& operator+=(const point& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        int x = 0;
        int y = 0;
    };


 




}