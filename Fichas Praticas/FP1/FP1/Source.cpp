#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* pfile; // Apontador para uma estrutura de um ficheiro
	char nome_ficheiro[] = { "teste.txt" }; // String com o nome do ficheiro
	int* valores; // Apontador para o Array din�mico que guarda os valores // lidos do ficheiro
	int nlinhas; // N� de dados que o ficheiro cont�m
	int nclasses; // N� de classes do histograma
	int i = 0;
	///////////////////////////////////////////////////////////
	// Leitura dos dados de um ficheiro para o array valores
	//

	pfile = fopen(nome_ficheiro, "r"); // Abertura do ficheiro em modo de leitura
	if (pfile == NULL) // Erro na abertura do ficheiro
		printf("Erro na abertura do ficheiro: %s\n", nome_ficheiro);
	else // Ficheiro aberto sem qualquer problema
	{
		// Leitura da 1� linha com o n� de classes do histograma
		fscanf(pfile, "%d", &nclasses);
		printf("%d\n", nclasses);
		// Leitura da 2� linha com o total de valores a ler
		fscanf(pfile, "%d", &nlinhas);
		printf("%d\n", nlinhas);
		valores = new int[nlinhas];
		// Leitura das linhas seguintes
		for (i; i < nlinhas; i++) {
			fscanf(pfile, "%d", &valores[i]);
			printf("%d, ", valores[i]);
		}
		
		delete[] valores; // Liberta��o da mem�ria ocupada pelo array din�mico
	}
}