#pragma once

#include <memory>

namespace mtk {

    class window;



    class window_driver {
    public:
        friend class graphics_driver;

        window_driver();
        ~window_driver();

        void create(window *w);

        int scale(int n);

        

    private:
        struct context;
        std::unique_ptr<window_driver::context> m_ctx;

        

    };





}