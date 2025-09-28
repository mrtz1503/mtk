#pragma once

#include <vector>

#include "mtk/widget.h"


namespace mtk {

    class widget;

    class group : public widget {
    public:
        group() = default;
        group(const rect& bounds) : widget(bounds) {};

        void add(widget* wnd);
        void remove(widget* wnd);

        std::vector<widget*> children() const;


        virtual void resize(const mtk::size& sz) override;
        virtual void draw(canvas& c) override;


    private:

        std::vector<widget*> m_children;
    };



}