#pragma once
#include <Windows.h>
#include "Point.h"
class Window{
private:
	HWND windowId; 
	Point cur_coord; 
	bool bClick; 
	static Window* object; 
	static Window* GetObject();
public:
	Window();
	~Window() { };
	bool Create(const char* sTitle);
	static LRESULT CALLBACK WindowProc(HWND wndId, unsigned int msg, WPARAM wp, LPARAM lp);
	HWND GetWindowId() { return windowId; }
	bool HasClicked() { return bClick; }
	Point GetPoint() { return cur_coord; } 
};
