#pragma once

#include <memory>
#include "driver/system_driver.h"

namespace mtk {


    class app {
    public:

        void run();
        void stop();

    private:

        bool m_running = false;

        system_driver m_sys;

    };



}