#define _CRT_SECURE_NO_WARNINGS

#include "Circle.h"
#include "Window.h"
#include "Point.h"
#include <Windows.h>
#include "Line.h"
#include <stdio.h>
#include <stdlib.h>
#include "Edge.h"
#include "Graph.h"

#define VERDE RGB(0,255,0)
#define AZUL RGB(0,255,255)
#define VERMELHO RGB(255,0,0)
#define CINZENTO RGB(128,128,128)

int main() {
	FILE *FichMapa, *FichRede;
	int *value, *x, *y;
	int nCircles=0, clicks=0, nLines=0;
	Point *center;
	Window window;
	HWND windowId;
	Circle* Circles;
	Line* line;
	int start, finish;
	bool found=0;
	printf("Programa que utiliza outra janela para os resultados.\n");
	FichMapa = fopen("Mapa.txt", "r");
	if (FichMapa == NULL)
		printf("Erro a abrir o ficheiro Mapa.txt\n");
	else
	{
		fscanf_s(FichMapa, "%d", &nCircles);
		x = new int[nCircles];
		y = new int[nCircles];
		center = new Point[nCircles];
		value = new int[nCircles];
		Circles = new Circle[nCircles];
		Edge edge;
		Graph map(nCircles);
		
		
		for (int i = 0; i < nCircles; i++) {
			fscanf_s(FichMapa, "%d, %d", &x[i], &y[i]);
			center[i] = Point(x[i], y[i]);
			Circles[i] = Circle(center[i], 13, (i + 1));
		}
		FichRede = fopen("Rede.txt", "r");
		if (FichRede == NULL)
			printf("Erro a abrir o ficheiro Rede.txt\n");
		else {
			fscanf_s(FichRede, "%d", &nLines);
			line = new Line[nLines];
			int a = 0, b = 0, c;
			for (int j = 0; j < nLines; j++) {
				fscanf_s(FichRede, "%d, %d", &a, &b);
				c = center[a - 1].GetDistance(center[b - 1]);
				line[j] = Line(center[a - 1], center[b - 1]);
				edge = Edge((a - 1), (b - 1), c);
				map.InsertEdge(edge);
			}
			printf("Matriz de adjacencias: \n");
			map.WriteADJ();
			fclose(FichRede);
		}
		fclose(FichMapa);
		if (window.Create("T6_47521_47694", "Mapa.bmp")) {
			if ((windowId = window.GetId()) != NULL) {
				for (int i = 0; i < nCircles; i++)
					Circles[i].Draw(windowId, CINZENTO);
				MSG msg;
				start = finish = -1;

				while (GetMessage(&msg, 0, 0, 0)) {
					DispatchMessage(&msg);
					if (window.Click()) {
						InvalidateRect(windowId, NULL, TRUE);
						UpdateWindow(windowId);
						for (int i = 0; i < nCircles; i++)
							Circles[i].Draw(windowId, CINZENTO);
						Point p = window.GetPoint();
						if (clicks < 2) 
						{
							for (int i=0; i<nCircles; i++)
								if (Circles[i].Contains(p))
								{
									if (clicks == 0)
										start = i;
									else
										finish = i;
									Circles[i].Draw(windowId, VERDE);
									clicks++;
									found = true;
								}
							if (!found)
							{
								start = -1;
								finish = -1;
								for (int i = 0; i < nCircles; i++){
									Circles[i].Draw(windowId, VERDE);
									clicks = 0;
								}
							}
						}
						else
							for (int i = 0; i < nCircles; i++) {
								Circles[i].Draw(windowId, CINZENTO);
								clicks = 0;
								start = -1;
								finish = -1;
							}
						if (finish >= 0){
							if (start > finish) {
								int temp = start;
								start = finish;
								finish = temp;
							}
							map.Dijkstra(start);
							map.WriteMinCostPath();
							Line Path;
							int a = finish, b, count = 0, c = 0;
							printf("\nP.Inicial: %d   P.Final: %d\n", start+1, finish+1);
							while (a != start) { //ultimo vertice ate o vertice anterior = start
								b = a;
								a = map.PrevVert(a);//a fica com o valor do vertice anterior
								count++;
								printf("Ponto 1: %d   Ponto 2: %d   Total: %d\n", a, b, count);
								Path = Line(center[a], center[b]);
								Path.Draw(windowId, VERMELHO);
								Circles[a].Draw(windowId, VERDE);
							}
							Circles[start].Draw(windowId, VERDE);
							c = map.PathWeight(finish);
							printf("\nDistancia do ponto %d ao ponto %d: %d\n", (start + 1), (finish + 1), c);
						}
					}
				}
			}
		}
	}
}
LRESULT CALLBACK WindowProcedure(HWND hwnd, unsigned int message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}