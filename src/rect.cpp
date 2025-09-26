#include "mtk/rect.h"

namespace mtk {

    int rect::width() const
    {
        return right - left;
    }

    int rect::height() const
    {
        return bottom - top;
    }

    int rect::x() const
    {
        return left;
    }

    int rect::y() const
    {
        return top;
    }



}