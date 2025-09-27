#include "mtk/canvas.h"

#include "mtk/widget.h"


namespace mtk {


    void canvas::line(int x1, int y1, int x2, int y2)
    {
        m_drv->line(x1, y1, x2, y2);
    }

    void canvas::fill(const color& c)
    {

        mtk::size sz = m_widget->size();

        m_drv->color(c);
        m_drv->rect_fill(0, 0, sz.width, sz.height);

    }



}