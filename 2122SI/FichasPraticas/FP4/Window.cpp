#include "Window.h"
Window* Window::object = NULL;// Objecto estático da classe Window que é utilizado
							  // dentro da função CALLBACK
Window::Window(){
	windowId= NULL;
	object = this;// Uma vez criado o objecto estático é o próprio objecto
	bClick = false;
}
Window* Window::GetObject(){return object;}
bool Window::Create(const char* sTitle){
	WNDCLASSEX wndclass = { sizeof(WNDCLASSEX), CS_DBLCLKS, WindowProc,0, 0, GetModuleHandle(0), LoadIcon(0,IDI_APPLICATION),LoadCursor(0,IDC_ARROW), HBRUSH(CTLCOLOR_STATIC+1),0, "myclass", LoadIcon(0,IDI_APPLICATION) };
	if( RegisterClassEx(&wndclass) ){ 
		// Função do SO Windows que cria janelas
		windowId = CreateWindowEx( 0, "myclass", sTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, GetModuleHandle(0), 0 );
		if(windowId){
			ShowWindow( windowId, SW_SHOWDEFAULT);
			return true;
		}
	}return false;
}
LRESULT CALLBACK Window::WindowProc(HWND wndId, unsigned int msg, WPARAM wp, LPARAM lp){
	Window* window = GetObject();
	window->bClick= false;
	switch(msg) {
	case WM_DESTROY:
		PostQuitMessage(0) ;
		return 0;
	case WM_KEYDOWN:
		if(wp== VK_ESCAPE){
			PostQuitMessage(0) ;
			return 0;
		}
		break;
	case WM_LBUTTONDOWN:
		window->bClick= true;
		window->cur_coord = Point(LOWORD(lp), HIWORD(lp));
		break;
	default:
		break;
	}
	return DefWindowProc(wndId, msg, wp, lp);
}