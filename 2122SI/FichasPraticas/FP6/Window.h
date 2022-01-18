#pragma once 
#include <Windows.h> 
#include "Point.h"

class Window {
private:
	HWND windowId;
	Point cur_coord;
	bool HasClicked;

	static Window* Object;
	static Window* GetObject();
public:
	Window();
	~Window() { };
	bool Create(const char* sTitulo);
	static LRESULT CALLBACK DispatchMessage(HWND janId, unsigned int msg, WPARAM wp, LPARAM lp);
	HWND GetId() {
		return windowId;
	}
	bool Click() {
		return HasClicked;
	}

	Point GetPoint(){
		return cur_coord;
	}
	// variável sImageName deve conter o caminho para o ficheiro com a imagem do mapa
	bool Create(const char* sTitle, const char* sImageName);
};

