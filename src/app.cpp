#include "mtk/app.h"

#include "mtk/driver/system_driver.h"

namespace mtk {


  

    void app::run()
    {
        m_running = true;
        
        while (m_running && m_sys.pump()) {}
    }

    void app::stop()
    {
        m_running = false;
    }





}