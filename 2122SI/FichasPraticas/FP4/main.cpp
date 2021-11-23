#include <stdio.h>
#include "Window.h"
#include "Circle.h"
#include "Point.h"
#include "Line.h"
#define VERDE RGB(0,255,0)
#define AZUL RGB(0,0,255)
#define VERMELHO RGB(255,0,0)
int main() {
	Window window; 
	HWND windowId;
	int nrpontos = 0;
	double comptotal = 0;
	printf("Programa que utiliza outra janela para os resultados.\n");
	if(window.Create("MyWindow")) {
		if((windowId=window.GetWindowId()) != NULL) {
			MSG msg ;
			Point inicial;
			while( GetMessage( &msg, 0, 0, 0 ) ) {
				DispatchMessage(&msg);
				if(window.HasClicked()){
					printf("Clicou em (%d, %d)\n", window.GetPoint().GetX(), window.GetPoint().GetY());
					Circle bola(window.GetPoint(),10);
					bola.Draw(windowId, AZUL);
					nrpontos += 1;
					if (nrpontos % 2 == 0) {
						Point final(window.GetPoint());
						Line linha(inicial, final);
						linha.Draw(windowId, VERDE);
						comptotal += linha.GetLength();
						printf("Comprimento da linha entre o ponto (%d, %d) e (%d, %d) = %.2f\nComprimento total ate agora = %.2f\n\n", inicial.GetX(), inicial.GetY(), final.GetX(), final.GetY(), linha.GetLength(), comptotal);
					}
					else{
						inicial.SetX(window.GetPoint().GetX());
						inicial.SetY(window.GetPoint().GetY());
					}
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