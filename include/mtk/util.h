#pragma once

#include <string>

namespace mtk {


	class util {
	public:

		static std::string wchar_to_utf8(const std::wstring& wstr);
		static std::wstring utf8_to_wchar(const std::string& str);

	private:

	};

}