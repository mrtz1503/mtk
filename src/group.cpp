#include "mtk/group.h"

#include "mtk/window.h"

#include <cassert>

namespace mtk {


    void group::add(widget* w)
    {
        assert(w != nullptr);

        // search and remove if found
        for (size_t i = 0; i < m_children.size(); i++)
            if (m_children[i] == w)
                m_children.erase(m_children.begin() + i);

        // add at end
        m_children.push_back(w);

        w->attach_to(this);
    }


    void group::remove(widget* w)
    {


    }




    std::vector<widget*> group::children()  const { return m_children; };


    void group::resize(const mtk::size& sz)
    {
        widget::resize(sz);

        int x = 0,
            y = 0;

        mtk::size sz_ = size();

        for (widget* w : m_children)
        {
            w->move({ x, y });
            w->resize({ sz_.width / static_cast<int>(m_children.size()), sz_.height });
            x += sz_.width / static_cast<int>(m_children.size());
        }


    }

    void group::draw(canvas& c)
    {
        widget::draw(c);

        for (widget* child : m_children)
        {
            canvas c_(child, c.driver());
            child->draw(c_);

        }

    }



}