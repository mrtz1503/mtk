#pragma once

#include "mtk/group.h"

#include "mtk/driver/graphics_driver.h"


namespace mtk {

    class box : public group {
    public:

        box(const color& c) : m_color(c) {};

        virtual void draw(canvas& c) override
        {
            c.rect(0, 0, c.size().width, c.size().height);
        }



    private:
        color m_color;

    };







}