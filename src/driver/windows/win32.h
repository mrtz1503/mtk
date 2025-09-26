#pragma once


#include <Windows.h>
#include <string>

namespace mtk {

    std::string get_msg_str(UINT code);

    std::string wchar_to_utf8(const std::wstring& wstr);
    std::wstring utf8_to_wchar(const std::string& str);


}
