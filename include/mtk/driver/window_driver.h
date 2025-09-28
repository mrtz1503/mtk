#pragma once

#include <memory>
#include "mtk/size.h"

namespace mtk {

    class window;



    class window_driver {
    public:
        friend class graphics_driver;

        window_driver();
        ~window_driver();

        void create(mtk::window* w);


        int scale(int n) const { return n * m_scale; };
        int unscale(int n) const { return n / m_scale; };

        float get_scale() const { return m_scale; };
        void set_scale(float scale) { m_scale = scale; };


        void resize(const size& sz);

        mtk::window* window() const;

    private:

        float m_scale = 1.0f;

        mtk::window* m_window;

        struct context;
        std::unique_ptr<window_driver::context> m_ctx;

    };





}