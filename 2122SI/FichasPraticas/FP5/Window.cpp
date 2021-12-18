#include "Window.h"

Window* Window::object = NULL;

Window::Window(){
	windowId= NULL;
	object = this;
	bClick = false;
}

Window* Window::GetObject(){return object;}

bool Window::Create(const char* sTitle){
	WNDCLASSEX wndclass = { sizeof(WNDCLASSEX), CS_DBLCLKS, WindowProc,0, 0, GetModuleHandle(0), LoadIcon(0,IDI_APPLICATION),LoadCursor(0,IDC_ARROW), HBRUSH(CTLCOLOR_STATIC+1),0, "myclass", LoadIcon(0,IDI_APPLICATION) };
	if( RegisterClassEx(&wndclass) ){ 
		// Função win que cria janelas
		windowId = CreateWindowEx( 0, "myclass", sTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, GetModuleHandle(0), 0 );
		if(windowId){
			ShowWindow( windowId, SW_SHOWDEFAULT);
			return true;
		}
	}return false;
}

LRESULT CALLBACK Window::WindowProc(HWND wndId, unsigned int msg, WPARAM wp, LPARAM lp)
{
	Window* window = GetObject();
	window->bClick = false;
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		if (wp == VK_ESCAPE) {
			PostQuitMessage(0);
			return 0;
		}
		else if (wp == VK_RETURN)
			window->bEnter = true;
		break;
	case WM_LBUTTONDOWN:
		window->bClick = true;
		window->cur_coord = Point(LOWORD(lp), HIWORD(lp));
		break;
	default:
		break;
	}
	return DefWindowProc(wndId, msg, wp, lp);
}
Point Window::GetBottomRight()
{
	Point bottom_right;
	Window* window = GetObject();
	RECT rec;
	GetClientRect(window->windowId, &rec);
	bottom_right = Point(rec.right, rec.bottom);
	return bottom_right;
}
void Window::Clean()
{
	RECT rec;
	Window* window = GetObject();
	GetClientRect(window->windowId, &rec);
	InvalidateRect(window->windowId, &rec, TRUE);
	UpdateWindow(windowId);
}