#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Window.h"
#include "Circle.h"
#include "Point.h"
#include "Queue.h"
#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)
#define CINZENTO RGB(140,140,140)

int main() {
	Window window; 
	HWND windowId;
	int nrpontos = 0;
	double comptotal = 0;
	if(window.Create("MyWindow")) {
		if((windowId=window.GetWindowId()) != NULL) {
			MSG msg ;
			Point inicial;
			Point ponto1(window.GetBottomRight().GetX() / 2, window.GetBottomRight().GetY() / 2);
			Point ponto2(window.GetBottomRight().GetX() / 4, window.GetBottomRight().GetY() *3/4);
			Point ponto3(window.GetBottomRight().GetX() / 4, window.GetBottomRight().GetY() / 2);
			Point ponto4(window.GetBottomRight().GetX() / 4, window.GetBottomRight().GetY() / 4);
			Circle bola1(ponto1, 30), bola2(ponto2, 30), bola3(ponto3, 30), bola4(ponto4, 30);
			Element* data;
			Queue queue;
			int totalval = 0;
			while( GetMessage( &msg, 0, 0, 0 ) ) {
				DispatchMessage(&msg);
				if (totalval < 4) {
					window.Clean();
					bola1.Draw(windowId, CINZENTO);
					bola2.Draw(windowId, CINZENTO);
					bola3.Draw(windowId, CINZENTO);
					bola4.Draw(windowId, CINZENTO);
				}
				if (window.HasPressEnter()) {
					data = new Element();
					data->get();
					queue.put(data);
					totalval += 1;
					printf("totalval=%d\n", totalval);
					if (totalval >= 4) {
						printf("totalval=%d!", totalval);
						bola1.Draw(windowId, VERDE, "1", AZUL);
						bola2.Draw(windowId, CINZENTO, "2", AZUL);
						bola3.Draw(windowId, CINZENTO, "3", AZUL);
						bola4.Draw(windowId, CINZENTO, "4", AZUL);
					}
				}
				if(window.HasClicked()&&(totalval!=0)){
					data = queue.get();
					delete data;
					totalval -= 1;
				}
			}
		}
	}
}
LRESULT CALLBACK WindowProcedure(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam) { 
	switch (message) { 
	case WM_DESTROY:
		PostQuitMessage(0); 
		return 0; 
	}
	return DefWindowProc(hwnd, message, wParam, lParam); 
}