#include "mtk/widget.h"

#include "mtk/point.h"
#include "mtk/size.h"

namespace mtk {

    void widget::attach_to(widget* parent)
    {
        m_parent = parent;
    }

    widget* widget::parent() const
    {
        return m_parent;
    }



    point widget::position() const
    {
        return { m_bounds.x(), m_bounds.y() };
    }

    void widget::move(const point& pos)
    {
        m_bounds.right = m_bounds.right - m_bounds.left + pos.x;
        m_bounds.left = pos.x;
        
        m_bounds.bottom = m_bounds.bottom - m_bounds.top + pos.y;
        m_bounds.top = pos.y;
    }


    mtk::size widget::size() const
    {
        return { m_bounds.width(), m_bounds.height() };
    }

    void widget::resize(const mtk::size& sz)
    {
        m_bounds.right = m_bounds.left + sz.width;
        m_bounds.bottom = m_bounds.top + sz.height;
    }

    /*int widget::scale(int n) const
    {
        return n * m_scale;
    }

    int widget::unscale(int n) const
    {
        return n / m_scale;
    }


    float widget::get_scale() const { return m_scale; }
    void widget::set_scale(float scale) { m_scale = scale; }*/




}

