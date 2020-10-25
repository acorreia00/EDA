#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void print() {
	printf("\n\nValor           Freq Absoluta           Freq Relativa           Representacao Grafica");
}

int main()
{
	FILE* pfile; // Apontador para uma estrutura de um ficheiro
	char nome_ficheiro[] = { "teste.txt" }; // String com o nome do ficheiro
	int* freqs;  // Apontador para o Array dinâmico que guarda os valores de Frequencia Absoluta
	int* valores; // Apontador para o Array dinâmico que guarda os valores // lidos do ficheiro
	int nlinhas; // Nº de dados que o ficheiro contém
	int nclasses; // Nº de classes do histograma
	int i = 0;
	int max = 0, min = 0;
	int freqval = 0;
	double media = 0,medsum=0, desv = 0,desvsum=0;
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
		printf("Numero de Classes: %d\n", nclasses);
		// Leitura da 2ª linha com o total de valores a ler
		fscanf(pfile, "%d", &nlinhas);
		printf("Numero de Linhas: %d\n", nlinhas);
		valores = new int[nlinhas];
		// Leitura das linhas seguintes
		printf("Amostra de Dados: ");
		for (i=0; i < nlinhas; i++) {
			fscanf(pfile, "%d", &valores[i]);
			printf("%d ", valores[i]);

			if (min > valores[i])  //
				min = valores[i];  //
								   // Valor maximo e minimo da amostra de forma a calcular Intervalos de Valores
			if (max < valores[i])  //
				max = valores[i];  //

			medsum = medsum + valores[i];  // Soma de Todos os Valores

			desvsum = desvsum + pow((valores[i] - media), 2);  // Parte do Calculo do Desvio Padrao
			
		}
		freqval = (max - min) / nclasses; // Intervalos de Valores na tabela a apresentar
		media = medsum / nlinhas;  // Media
		desv = sqrt(desvsum / nlinhas);  // Desvio Padrao
		freqs = new int[freqval];
		print();  // Print da Tabela
		delete[] valores; // Libertação da memória ocupada pelo array dinâmico
		delete[] freqs;  // Libertação da memória ocupada pelo array dinâmico
	}
}