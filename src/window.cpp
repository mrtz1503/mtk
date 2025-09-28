#include "mtk/window.h"

#define UNICODE
#include <Windows.h>

#include <stdexcept>
#include <iostream>


#include "mtk/util.h"

#include "mtk/size.h"
#include "mtk/point.h"

namespace mtk {



    window::window(std::string name, const rect& bounds) : group(bounds), m_name(std::move(name)) {};


    void window::show()
    {
        m_drv.create(this);
    }

    std::string window::get_name() const
    {
        return m_name;
    }

    window_driver& window::driver()
    {
        return m_drv;
    }

   



}