#pragma once
#include "windows.h"
#include <iostream>
#include <string>
#define OnButton 1
POINT p;
INPUT m;
std::string str;

LPCSTR convertStringToLPCSTR(std::string str);
LPCSTR str1;
LPCSTR str2;

int i = 0;
void AddWndVidget(HWND hWnd);
HWND editText;
HWND editText2;
HWND ButtonWnd;
//#define WM_NCMOUSEMOVE 
void addWindow();
std::string addXToString(std::string str);
std::string addYToString(std::string str);


