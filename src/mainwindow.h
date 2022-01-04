/*
 * Copyright 2021 Andi Machovec <andi.machovec@gmail.com>
 * All rights reserved. Distributed under the terms of the MIT license.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <Window.h>
#include <MenuBar.h>


class BoardView;
class PegSelectView;
class ButtonView;
class TimerView;


enum
{
	MW_MENU_ABOUT ='mw00',
	MW_MENU_NEWGAME,
	MW_MENU_RULES,
};


class MainWindow : public BWindow {
public:
	MainWindow(BRect geometry);
	~MainWindow();
	void MessageReceived(BMessage *msg);
	bool QuitRequested();

private:
	BMenuBar			*fTopMenuBar;
	BoardView			*fBoardView;
	PegSelectView		*fPegSelectView;
	ButtonView			*fButtonView;
	TimerView			*fTimerView;

};

#endif
