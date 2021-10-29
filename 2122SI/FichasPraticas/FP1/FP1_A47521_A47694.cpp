#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Afonso Correia 47521
  Diogo Justino 47694*/

void estatisticas(int nlinhas, float* val, float& media, float& dp);

int main()
{
	FILE* pfile;
	char nome_ficheiro[] = { "dados.txt" };
	float* valores;
	// lidos do ficheiro
	int nclasses, nlinhas; // Nº de classes do histograma
	//intervalos de valores e  Nº de dados que o ficheiro contém
	float vmax = 0, vmin = 0;
	// Leitura dos dados de um ficheiro para o array valores
	//
	pfile = fopen(nome_ficheiro, "r"); // Abertura do ficheiro em modo de leitura
	if (pfile == NULL) {// Erro na abertura do ficheiro
		printf("Erro na abertura do ficheiro: %s\n", nome_ficheiro);
		system("pause");
		exit(0);
	}
	else // Ficheiro aberto sem qualquer problema
	{
		// Leitura da 1ª linha com o nº de classes do histograma
		fscanf(pfile, "%d", &nclasses);
		// Leitura da 2ª linha com o total de valores a ler
		fscanf(pfile, "%d", &nlinhas);
		valores = new float[nlinhas];
		// Leitura das linhas seguintes
		for (int i = 0; i < nlinhas; i++) {
			fscanf(pfile, "%f,", &valores[i]);
			if (valores[i] > vmax || i==0) vmax = valores[i];
			if (valores[i] < vmin || i == 0) vmin = valores[i];
		}
		printf("Valor \t \t Freq absoluta  \t    Freq relativa  \t  Representacao grafica\n\n");
		//ja se tem os 2 valores, o maior e o menor
		float intervalos;
		intervalos = (vmax - vmin) / nclasses;
		for (int i = 0; i < nclasses;i++) {                       //////////////////////             i + 1 == nclasses) && (valores[j] == (vmin + (intervalos * (i+1)) freq++;
			printf("%.2f a %.2f", vmin + (intervalos *i), vmin + (intervalos * (i+1)));
			printf("\t\t");
			float freq = 0;
			for (int j = 0; j < nlinhas; j++){
				if ((valores[j] >= vmin + (intervalos * i)) && (valores[j] < vmin + (intervalos * (i+1)))) freq++;
				if (((i + 1) == nclasses) && (valores[j] == (vmin + (intervalos * (i + 1))))) freq++;
			}
			printf("%g", freq);																    //printf da freq absoluta
			printf("\t\t\t");
			int freqg = freq;
			freq /= nlinhas;
			printf("%g%%", freq* 100);														    // calculo e printf da freq relativa
			printf(" \t \t \t");
			for (int i = 0;i < freqg;i++) {                                                      // representacao grafica
				printf("*");
			}
			printf("\n");
		}
		////passos seguintes////
		float media = 0, dpadrao = 0;
		estatisticas(nlinhas, valores, media, dpadrao);
		printf("\n");
		printf("M%cdia = %g \tDesvio Padr%co = %g\n", 130, media, 198, dpadrao);
		printf("\n");
		//printf("nlinhas %d nclasses %d", nlinhas, nclasses);
		printf("O valor m%cximo %c %g, e o valor minimo %c %g",160, 130,vmax, 130 , vmin);
		printf("\n\n");
		
		//delete[] freq;// Libertação da memória ocupada pelo array dinâmico
		delete[] valores; // Libertação da memória ocupada pelo array dinâmico
		fclose(pfile);
	}
}

void estatisticas(int nlinhas, float* val, float& media, float& dp)
{
	for (int i = 0; i < nlinhas; i++) {
		media += val[i];
	}
	media /= nlinhas;
	for (int i = 0; i < nlinhas; i++) {
		dp += ((val[i] - media) * (val[i] - media));
	}
	dp = sqrt(dp / nlinhas);
}