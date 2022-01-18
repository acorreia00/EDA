#include "Window.h"
#include <stdio.h>
#include <stdlib.h>

Window* Window::Object = NULL; // Objecto estático da classe Janela que é utilizado dentro da função CALLBACK

Window::Window()
{
	windowId = NULL;
	Object = this; // Uma vez criado o objecto estático é o próprio objecto
	HasClicked = false;
}
Window* Window::GetObject()
{
	return Object;
}
bool Window::Create(const char* sTitulo)
{
	WNDCLASSEX wndclass = { sizeof(WNDCLASSEX), CS_DBLCLKS, DispatchMessage,
		0, 0, GetModuleHandle(0), LoadIcon(0, IDI_APPLICATION),
		LoadCursor(0, IDC_ARROW), HBRUSH(CTLCOLOR_STATIC + 1),
		0, "minhaclasse", LoadIcon(0, IDI_APPLICATION) };

	if (RegisterClassEx(&wndclass))
	{ // Função do SO Windows que cria janelas
		windowId = CreateWindowEx(0, "minhaclasse", sTitulo,
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, GetModuleHandle(0), 0);
		if (windowId)
		{
			ShowWindow(windowId, SW_SHOWDEFAULT);
			return true;
		}
	}
	return false;
}

LRESULT CALLBACK Window::DispatchMessage(HWND janId, unsigned int msg,
	WPARAM wp, LPARAM lp)
{
	Window* window = Object;
	window->HasClicked = false;

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		if (wp == VK_ESCAPE) {
			PostQuitMessage(0);
			return 0;
		}
		break;
	case WM_LBUTTONDOWN:
		window->HasClicked = true;
		window->cur_coord = Point(LOWORD(lp), HIWORD(lp));
		break;
	default:
		break;
	}
	return DefWindowProc(janId, msg, wp, lp);
}

bool Window::Create(const char* sTitulo, const char* sImageName)
{
	WNDCLASSEX wndclass = { sizeof(WNDCLASSEX), CS_DBLCLKS, DispatchMessage,
		0, 0, GetModuleHandle(0), LoadIcon(0, IDI_APPLICATION),
		LoadCursor(0, IDC_ARROW), CreatePatternBrush((HBITMAP) LoadImage(0, sImageName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE)), 0, "minhaclasse",LoadIcon(0, IDI_APPLICATION)};

	if (RegisterClassEx(&wndclass))
	{ // Função do SO Windows que cria janelas
		windowId = CreateWindowEx(0, "minhaclasse", sTitulo,
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			883, 566, 0, 0, GetModuleHandle(0), 0);
		if (windowId)
		{
			ShowWindow(windowId, SW_SHOWDEFAULT);
			return true;
		}
	}
	return false;
}
