#include "peg.h"


Peg::Peg(BView *target, BPoint center, float radius, rgb_color color)
	:
	fTarget(target),
	fCenter(center),
	fRadius(radius),
	fColor(color)
{

}


void
Peg::Draw()
{
	rgb_color temp_color = fTarget->HighColor();
	fTarget->SetHighColor(fColor);
	fTarget->FillEllipse(fCenter, fRadius, fRadius, B_SOLID_HIGH);
	fTarget->SetHighColor(temp_color);

}


void
Peg::SetCenter(BPoint center)
{

	fCenter = center;

}