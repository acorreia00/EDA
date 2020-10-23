#include <stdio.h>
void main()
{
	FILE* pfile; // Apontador para uma estrutura de um ficheiro
	char nome_ficheiro[] = { "c:\\Teste.txt" }; // String com o nome do ficheiro
	float* valores; // Apontador para o Array dinâmico que guarda os valores // lidos do ficheiro
	int nlinhas; // Nº de dados que o ficheiro contém
	int nclasses; // Nº de classes do histograma
	///////////////////////////////////////////////////////////
	// Leitura dos dados de um ficheiro para o array valores
	//

	pfile = fopen(nome_ficheiro, "r"); // Abertura do ficheiro em modo de leitura
	if (pfile == NULL) // Erro na abertura do ficheiro
		printf("Erro na abertura do ficheiro: %s\n", nome_ficheiro);
	else // Ficheiro aberto sem qualquer problema
	{
		// Leitura da 1ª linha com o nº de classes do histograma
		fscanf(pfile, "%d", &nclasses);
		// Leitura da 2ª linha com o total de valores a ler
		fscanf(pfile, "%d", &nlinhas);
		valores = new float[nlinhas];
		// Leitura das linhas seguintes
		for (i = 0; i < nlinhas; i++)
			fscanf(pfile, "%f", &valores[i]);
		///////////////////////////////////////////////////////////
		// C O M P L E T A R
		delete[] valores; // Libertação da memória ocupada pelo array dinâmico