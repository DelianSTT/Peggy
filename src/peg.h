/*
 * Copyright 2021 Andi Machovec <andi.machovec@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 *
 */

#ifndef PEG_H
#define PEG_H


#include <View.h>
#include <Bitmap.h>

#include <array>


class Peg {
public:
	Peg();
	Peg(BView *target, BPoint center, float radius, uint8 color_index, bool with_outline=true);
	~Peg();
	void Draw();
	void SetTarget(BView *target);
	void SetCenter(BPoint center);
	void SetRadius(float radius);
	void SetColorIndex(uint8 color_index);
	void SetOutline(bool with_outline);
	uint8 GetColorIndex();
	bool Contains(BPoint point);
	BBitmap* GetBitmap();
	BPoint GetCenter();

private:
	void create_bitmap();
	void draw_peg(BView *drawing_view, BPoint center, bool draw_outline);
	void init_colors();

	BView *fTarget;
	BPoint fCenter;
	float fRadius;
	std::array<rgb_color, 9> fColors;
	uint8 fColorIndex;
	BBitmap *fBitmap;
	bool fWithOutline;

};


#endif
