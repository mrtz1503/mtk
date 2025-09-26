#pragma once

#include <string>
#include <set>
#include <memory>

#include "mtk/group.h"
#include "mtk/widget.h"

#include "mtk/driver/window_driver.h"
#include "mtk/rect.h"
#include "mtk/point.h"
#include "mtk/size.h"

namespace mtk {

    class window_driver;

    class window : public group {
    public:
        friend class graphics_driver;



        window(std::string name, const rect& bounds = { 100,100,900,700 });

        void show();
        //bool is_visible();



        std::string get_name() const;

    protected:
        window_driver& driver();


    private:

        window_driver m_drv;
        std::string m_name;


    };



}