#pragma once

namespace mtk {


    struct rect {

        int width() const;
        int height() const;
        int x() const;
        int y() const;


        int left = 0;
        int top = 0;
        int right = 0;
        int bottom = 0;



    };

}