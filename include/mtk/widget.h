#pragma once

#include "mtk/rect.h"
#include "mtk/point.h"
#include "mtk/size.h"
#include "mtk/canvas.h"


namespace mtk{

	class widget {
	public:

		widget() = default;
		widget(const rect& bounds) : m_bounds(bounds) {};

		/*
		*	VISIBILITY
		*/

		void show(canvas &canva);
		//void hide();



		/*
		*	OWNING
		*/

		// sets the parent of this widget
		void attach_to(widget* parent);

		// returns the parent of this widget; nullptr if no parent is present
		widget* parent() const;
		


		/*
		*	SIZING and SCALING
		*/

		point position() const;
		void move(const point& pos);

		sz size() const;
		void resize(const sz& size);

		int scale(int n) const ;
		float get_scale() const;
		void set_scale(float scale);


		/*
		*	DRAWING
		*/

		virtual void draw(canvas &c) {};


	private:
		widget* m_parent = nullptr;

		rect m_bounds;

		float m_scale = 1.0;

	};


}