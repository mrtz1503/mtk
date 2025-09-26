#include "win32.h"

#include <stdexcept>
#include <string>
#include <memory>

namespace mtk {

    std::string get_msg_str(UINT code)
    {
        struct msg {
            UINT code;
            std::string text;
        };

        static msg messages[] = {
            { WM_NULL, "WM_NULL" },
            { WM_CREATE, "WM_CREATE" },
            { WM_DESTROY, "WM_DESTROY" },
            { WM_MOVE, "WM_MOVE" },
            { WM_SIZE, "WM_SIZE" },
            { WM_ACTIVATE, "WM_ACTIVATE" },
            { WM_SETFOCUS, "WM_SETFOCUS" },
            { WM_KILLFOCUS, "WM_KILLFOCUS" },
            { WM_ENABLE, "WM_ENABLE" },
            { WM_SETREDRAW, "WM_SETREDRAW" },
            { WM_SETTEXT, "WM_SETTEXT" },
            { WM_GETTEXT, "WM_GETTEXT" },
            { WM_GETTEXTLENGTH, "WM_GETTEXTLENGTH" },
            { WM_PAINT, "WM_PAINT" },
            { WM_CLOSE, "WM_CLOSE" },
            { WM_QUERYENDSESSION, "WM_QUERYENDSESSION" },
            { WM_QUIT, "WM_QUIT" },
            { WM_QUERYOPEN, "WM_QUERYOPEN" },
            { WM_ERASEBKGND, "WM_ERASEBKGND" },
            { WM_SYSCOLORCHANGE, "WM_SYSCOLORCHANGE" },
            { WM_ENDSESSION, "WM_ENDSESSION" },
            { WM_SHOWWINDOW, "WM_SHOWWINDOW" },
            { WM_WININICHANGE, "WM_WININICHANGE" },
            { WM_SETTINGCHANGE, "WM_SETTINGCHANGE" },  // alias of WM_WININICHANGE in newer SDKs
            { WM_DEVMODECHANGE, "WM_DEVMODECHANGE" },
            { WM_ACTIVATEAPP, "WM_ACTIVATEAPP" },
            { WM_FONTCHANGE, "WM_FONTCHANGE" },
            { WM_TIMECHANGE, "WM_TIMECHANGE" },
            { WM_CANCELMODE, "WM_CANCELMODE" },
            { WM_SETCURSOR, "WM_SETCURSOR" },
            { WM_MOUSEACTIVATE, "WM_MOUSEACTIVATE" },
            { WM_CHILDACTIVATE, "WM_CHILDACTIVATE" },
            { WM_QUEUESYNC, "WM_QUEUESYNC" },
            { WM_GETMINMAXINFO, "WM_GETMINMAXINFO" },
            { WM_PAINTICON, "WM_PAINTICON" },
            { WM_ICONERASEBKGND, "WM_ICONERASEBKGND" },
            { WM_NEXTDLGCTL, "WM_NEXTDLGCTL" },
            { WM_SPOOLERSTATUS, "WM_SPOOLERSTATUS" },
            { WM_DRAWITEM, "WM_DRAWITEM" },
            { WM_MEASUREITEM, "WM_MEASUREITEM" },
            { WM_DELETEITEM, "WM_DELETEITEM" },
            { WM_VKEYTOITEM, "WM_VKEYTOITEM" },
            { WM_CHARTOITEM, "WM_CHARTOITEM" },
            { WM_SETFONT, "WM_SETFONT" },
            { WM_GETFONT, "WM_GETFONT" },
            { WM_SETHOTKEY, "WM_SETHOTKEY" },
            { WM_GETHOTKEY, "WM_GETHOTKEY" },
            { WM_QUERYDRAGICON, "WM_QUERYDRAGICON" },
            { WM_COMPAREITEM, "WM_COMPAREITEM" },
            { WM_GETOBJECT, "WM_GETOBJECT" },
            { WM_COMPACTING, "WM_COMPACTING" },
            { WM_COMMNOTIFY, "WM_COMMNOTIFY" },
            { WM_WINDOWPOSCHANGING, "WM_WINDOWPOSCHANGING" },
            { WM_WINDOWPOSCHANGED, "WM_WINDOWPOSCHANGED" },
            { WM_POWER, "WM_POWER" },
            { WM_COPYDATA, "WM_COPYDATA" },
            { WM_CANCELJOURNAL, "WM_CANCELJOURNAL" },
            { WM_NOTIFY, "WM_NOTIFY" },
            { WM_INPUTLANGCHANGEREQUEST, "WM_INPUTLANGCHANGEREQUEST" },
            { WM_INPUTLANGCHANGE, "WM_INPUTLANGCHANGE" },
            { WM_TCARD, "WM_TCARD" },
            { WM_HELP, "WM_HELP" },
            { WM_USERCHANGED, "WM_USERCHANGED" },
            { WM_NOTIFYFORMAT, "WM_NOTIFYFORMAT" },
            { WM_CONTEXTMENU, "WM_CONTEXTMENU" },
            { WM_STYLECHANGING, "WM_STYLECHANGING" },
            { WM_STYLECHANGED, "WM_STYLECHANGED" },
            { WM_DISPLAYCHANGE, "WM_DISPLAYCHANGE" },
            { WM_GETICON, "WM_GETICON" },
            { WM_SETICON, "WM_SETICON" },
            { WM_NCCREATE, "WM_NCCREATE" },
            { WM_NCDESTROY, "WM_NCDESTROY" },
            { WM_NCCALCSIZE, "WM_NCCALCSIZE" },
            { WM_NCHITTEST, "WM_NCHITTEST" },
            { WM_NCPAINT, "WM_NCPAINT" },
            { WM_NCACTIVATE, "WM_NCACTIVATE" },
            { WM_GETDLGCODE, "WM_GETDLGCODE" },
            { WM_SYNCPAINT, "WM_SYNCPAINT" },
            { WM_NCMOUSEMOVE, "WM_NCMOUSEMOVE" },
            { WM_NCLBUTTONDOWN, "WM_NCLBUTTONDOWN" },
            { WM_NCLBUTTONUP, "WM_NCLBUTTONUP" },
            { WM_NCLBUTTONDBLCLK, "WM_NCLBUTTONDBLCLK" },
            { WM_NCRBUTTONDOWN, "WM_NCRBUTTONDOWN" },
            { WM_NCRBUTTONUP, "WM_NCRBUTTONUP" },
            { WM_NCRBUTTONDBLCLK, "WM_NCRBUTTONDBLCLK" },
            { WM_NCMBUTTONDOWN, "WM_NCMBUTTONDOWN" },
            { WM_NCMBUTTONUP, "WM_NCMBUTTONUP" },
            { WM_NCMBUTTONDBLCLK, "WM_NCMBUTTONDBLCLK" },
            { WM_KEYDOWN, "WM_KEYDOWN" },
            { WM_KEYUP, "WM_KEYUP" },
            { WM_CHAR, "WM_CHAR" },
            { WM_DEADCHAR, "WM_DEADCHAR" },
            { WM_SYSKEYDOWN, "WM_SYSKEYDOWN" },
            { WM_SYSKEYUP, "WM_SYSKEYUP" },
            { WM_SYSCHAR, "WM_SYSCHAR" },
            { WM_SYSDEADCHAR, "WM_SYSDEADCHAR" },
            { WM_UNICHAR, "WM_UNICHAR" },
            { WM_IME_STARTCOMPOSITION, "WM_IME_STARTCOMPOSITION" },
            { WM_IME_ENDCOMPOSITION, "WM_IME_ENDCOMPOSITION" },
            { WM_IME_COMPOSITION, "WM_IME_COMPOSITION" },
            { WM_INITDIALOG, "WM_INITDIALOG" },
            { WM_COMMAND, "WM_COMMAND" },
            { WM_SYSCOMMAND, "WM_SYSCOMMAND" },
            { WM_TIMER, "WM_TIMER" },
            { WM_HSCROLL, "WM_HSCROLL" },
            { WM_VSCROLL, "WM_VSCROLL" },
            { WM_INITMENU, "WM_INITMENU" },
            { WM_INITMENUPOPUP, "WM_INITMENUPOPUP" },
            { WM_MENUSELECT, "WM_MENUSELECT" },
            { WM_MENUCHAR, "WM_MENUCHAR" },
            { WM_ENTERIDLE, "WM_ENTERIDLE" },
            { WM_MENURBUTTONUP, "WM_MENURBUTTONUP" },
            { WM_MENUDRAG, "WM_MENUDRAG" },
            { WM_MENUGETOBJECT, "WM_MENUGETOBJECT" },
            { WM_UNINITMENUPOPUP, "WM_UNINITMENUPOPUP" },
            { WM_MENUCOMMAND, "WM_MENUCOMMAND" },
            { WM_CHANGEUISTATE, "WM_CHANGEUISTATE" },
            { WM_UPDATEUISTATE, "WM_UPDATEUISTATE" },
            { WM_QUERYUISTATE, "WM_QUERYUISTATE" },
            { WM_CTLCOLORMSGBOX, "WM_CTLCOLORMSGBOX" },
            { WM_CTLCOLOREDIT, "WM_CTLCOLOREDIT" },
            { WM_CTLCOLORLISTBOX, "WM_CTLCOLORLISTBOX" },
            { WM_CTLCOLORBTN, "WM_CTLCOLORBTN" },
            { WM_CTLCOLORDLG, "WM_CTLCOLORDLG" },
            { WM_CTLCOLORSCROLLBAR, "WM_CTLCOLORSCROLLBAR" },
            { WM_CTLCOLORSTATIC, "WM_CTLCOLORSTATIC" },
            { WM_MOUSEMOVE, "WM_MOUSEMOVE" },
            { WM_LBUTTONDOWN, "WM_LBUTTONDOWN" },
            { WM_LBUTTONUP, "WM_LBUTTONUP" },
            { WM_LBUTTONDBLCLK, "WM_LBUTTONDBLCLK" },
            { WM_RBUTTONDOWN, "WM_RBUTTONDOWN" },
            { WM_RBUTTONUP, "WM_RBUTTONUP" },
            { WM_RBUTTONDBLCLK, "WM_RBUTTONDBLCLK" },
            { WM_MBUTTONDOWN, "WM_MBUTTONDOWN" },
            { WM_MBUTTONUP, "WM_MBUTTONUP" },
            { WM_MBUTTONDBLCLK, "WM_MBUTTONDBLCLK" },
            { WM_MOUSEWHEEL, "WM_MOUSEWHEEL" },
            { WM_XBUTTONDOWN, "WM_XBUTTONDOWN" },
            { WM_XBUTTONUP, "WM_XBUTTONUP" },
            { WM_XBUTTONDBLCLK, "WM_XBUTTONDBLCLK" },
            { WM_MOUSEHWHEEL, "WM_MOUSEHWHEEL" },
            { WM_PARENTNOTIFY, "WM_PARENTNOTIFY" },
            { WM_ENTERMENULOOP, "WM_ENTERMENULOOP" },
            { WM_EXITMENULOOP, "WM_EXITMENULOOP" },
            { WM_NEXTMENU, "WM_NEXTMENU" },
            { WM_SIZING, "WM_SIZING" },
            { WM_CAPTURECHANGED, "WM_CAPTURECHANGED" },
            { WM_MOVING, "WM_MOVING" },
            { WM_POWERBROADCAST, "WM_POWERBROADCAST" },
            { WM_DEVICECHANGE, "WM_DEVICECHANGE" },
            { WM_MDICREATE, "WM_MDICREATE" },
            { WM_MDIDESTROY, "WM_MDIDESTROY" },
            { WM_MDIACTIVATE, "WM_MDIACTIVATE" },
            { WM_MDIRESTORE, "WM_MDIRESTORE" },
            { WM_MDINEXT, "WM_MDINEXT" },
            { WM_MDIMAXIMIZE, "WM_MDIMAXIMIZE" },
            { WM_MDITILE, "WM_MDITILE" },
            { WM_MDICASCADE, "WM_MDICASCADE" },
            { WM_MDIICONARRANGE, "WM_MDIICONARRANGE" },
            { WM_MDIGETACTIVE, "WM_MDIGETACTIVE" },
            { WM_MDISETMENU, "WM_MDISETMENU" },
            { WM_ENTERSIZEMOVE, "WM_ENTERSIZEMOVE" },
            { WM_EXITSIZEMOVE, "WM_EXITSIZEMOVE" },
            { WM_DROPFILES, "WM_DROPFILES" },
            { WM_MDIREFRESHMENU, "WM_MDIREFRESHMENU" },
            { WM_IME_SETCONTEXT, "WM_IME_SETCONTEXT" },
            { WM_IME_NOTIFY, "WM_IME_NOTIFY" },
            { WM_IME_CONTROL, "WM_IME_CONTROL" },
            { WM_IME_COMPOSITIONFULL, "WM_IME_COMPOSITIONFULL" },
            { WM_IME_SELECT, "WM_IME_SELECT" },
            { WM_IME_CHAR, "WM_IME_CHAR" },
            { WM_IME_REQUEST, "WM_IME_REQUEST" },
            { WM_IME_KEYDOWN, "WM_IME_KEYDOWN" },
            { WM_IME_KEYUP, "WM_IME_KEYUP" },
        };

        for (const msg& msg_ : messages)
            if (msg_.code == code)
                return msg_.text;

        return "UNKNOWN";
    }


    std::string wchar_to_utf8(const std::wstring& wstr)
    {
        if (wstr.empty())
            return {};

        int length = ::WideCharToMultiByte(CP_UTF8, 0, &wstr[0], static_cast<int>(wstr.size()), nullptr, 0, NULL, NULL);
        if (!length)
            throw std::runtime_error("util::wideCharToUtf8 -> ::WideCharToMultiByte failed");

        std::unique_ptr<char[]> buf = std::make_unique<char[]>(static_cast<size_t>(length) + 1);

        ::WideCharToMultiByte(CP_UTF8, 0, &wstr[0], static_cast<int>(wstr.size()), buf.get(), length + 1, NULL, NULL);

        return std::string(buf.get(), buf.get() + length);
    }


    std::wstring utf8_to_wchar(const std::string& str)
    {
        if (str.empty())
            return {};

        int length = ::MultiByteToWideChar(CP_UTF8, 0, &str[0], static_cast<int>(str.size()), nullptr, 0);
        if (!length)
            throw std::runtime_error("util::utf8ToWideChar() -> ::MultiByteToWideChar() failed");

        std::unique_ptr<wchar_t[]> buf = std::make_unique<wchar_t[]>(static_cast<size_t>(length) + 1);

        ::MultiByteToWideChar(CP_UTF8, 0, &str[0], static_cast<int>(str.size()), buf.get(), length + 1);

        return std::wstring(buf.get(), buf.get() + static_cast<size_t>(length));
    }


}