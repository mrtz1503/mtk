#include "mtk/driver/system_driver.h"

#include "win32.h"

#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <shellscalingapi.h>



namespace mtk {



    system_driver::system_driver() 
    {
        ::SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);
    }


    bool system_driver::pump()
    {
        MSG msg = { };
        if (::GetMessageW(&msg, nullptr, 0, 0) > 0)
        {
            std::cout << get_msg_str(msg.message) << " -> sys" << "\n";

            ::TranslateMessage(&msg);
            ::DispatchMessageW(&msg);

            return true;
        }

        return false;
    }


}