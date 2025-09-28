#include "mtk/canvas.h"

#include "mtk/driver/graphics_driver.h"
#include "mtk/widget.h"


namespace mtk {

    canvas::canvas(widget* w, graphics_driver* gd) : m_widget(w), m_drv(gd)
    {
        for (widget* widget = w; widget->parent() != nullptr; widget = widget->parent())
            m_offpos += widget->position();
    }

    void canvas::line(int x1, int y1, int x2, int y2)
    {
        m_drv->line(x1, y1, x2, y2);
    }

    void canvas::fill(const color& c)
    {
        mtk::size sz = size();

        m_drv->color(c);
        m_drv->rect_fill(m_offpos.x, m_offpos.y,
                         sz.width, sz.height);
    }

    void canvas::rect(int x1, int y1, int x2, int y2)
    {
        m_drv->color(colors::black);
        m_drv->rect(m_offpos.x + x1, m_offpos.y + y1, x2, y2);
    }


    mtk::size canvas::size()
    {
        return m_widget->size();
    }


    graphics_driver* canvas::driver() { return m_drv; };


}