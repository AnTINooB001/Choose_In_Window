#pragma once
#include "windows.h"
#include <iostream>
#include <string>

#define OnYes 0

HWND hWnd; //идентификатор окна

HWND YesButt;

POINT p;
INPUT m;

std::string Curstr;
std::string str;


POINT WndP1;

POINT WndP2;


LPCSTR Curstr1;
LPCSTR str1;
LPCSTR str2;

HWND WndText;
HWND WndText2;
HWND ButtonWnd;


HWND editText;
HWND editText2;


void AddWndVidget(HWND hWnd);

LPCSTR convertStringToLPCSTR(std::string str);

void addWindow();

std::string addXToString(std::string str);

std::string addYToString(std::string str);

void showCursCoordinates(int xPosCur, int yPosCur);

POINT Convert(HWND w, LONG& x, LONG& y);

void ShowWndPos(POINT p);


