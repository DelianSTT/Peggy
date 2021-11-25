#include "pegselectview.h"
#include "peg.h"
#include <iostream>


PegSelectView::PegSelectView()
	:
	BView("pegselectview", B_SUPPORTS_LAYOUT|B_WILL_DRAW|B_FULL_UPDATE_ON_RESIZE)
{

	//initialize peg colors
	fPegColors[0].set_to(255,0,0);
	fPegColors[1].set_to(0,255,0);
	fPegColors[2].set_to(0,0,255);
	fPegColors[3].set_to(255,255,0);
	fPegColors[4].set_to(255,0,255);
	fPegColors[5].set_to(255,179,71);

	//initialize pegs
	fPegRadius = 20;

	for(int i = 0; i < 6; ++i)
	{
		fPegs[i] = new Peg(this, BPoint(), fPegRadius, fPegColors[i]);
	}

}


void
PegSelectView::Draw(BRect updateRect)
{

	for(int i = 0; i < 6; ++i)
	{
		fPegs[i]->Draw();
	}

}


void
PegSelectView::LayoutChanged()
{

	float delta_y = (Bounds().Height() - 12*fPegRadius) / 7;

	BPoint peg_center;
	peg_center.x = Bounds().Width() / 2;
	peg_center.y = delta_y+fPegRadius;

	for(int i = 0; i < 6; ++i)
	{
		fPegs[i]->SetCenter(peg_center);
		peg_center.y += delta_y+2*fPegRadius;
	}

}


void
PegSelectView::MouseDown(BPoint point)
{

	std::cout << "MouseDown: X: " << point.x << "Y: " << point.y << std::endl;

}


void
PegSelectView::MouseMoved(BPoint point, uint32 transit, const BMessage* message)
{

	//std::cout << "MouseMoved: X: " << point.x << "Y: " << point.y << std::endl;
	for(int peg_nr = 0; peg_nr < 6; ++peg_nr)
	{
		if (fPegs[peg_nr]->Contains(point))
		{
			std::cout << "contained in peg " << peg_nr << std::endl;	
			break;
		}
	}
	
}



