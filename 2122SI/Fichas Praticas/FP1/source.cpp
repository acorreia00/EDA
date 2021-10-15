#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float* valores;
float max, min, media_total, desvio_padrao, amplitude;
int nlinhas;
int nclasses;
float desvioPadrao(float, int);
float media(float, int);
float amp(float, float);
int freqAbsoluta(int, int, int);
float freqRelativa(int, int, int);

int main()
{
	FILE* pfile;
	char nome_ficheiro[] = { "dados.txt" };

	//abrir ficheiro

	pfile = fopen(nome_ficheiro, "r");

	//verificação da abertura do ficheiro

	if (pfile == NULL)
	{
		printf(" Erro na abertura do ficheiro: %s\n", nome_ficheiro);
		system("pause");
		exit(1);
	}
	else
	{

		//leitura do número de classes e de linhas

		fscanf_s(pfile, "%d", &nclasses);
		fscanf_s(pfile, "%d", &nlinhas);

		valores = new float[nlinhas];
		max = min = 0;
		float soma = 0;

		//leitura dos valores da amostra e cálculo do máximo, mínimo e soma

		for (int i = 0; i < nlinhas; i++)
		{
			fscanf_s(pfile, "%f", &valores[i]);
			if (valores[i] > max) max = valores[i];
			if (valores[i] < min || i == 0) min = valores[i];
			soma += valores[i];
			printf("\n %1.0f", valores[i]);
		}
		media_total = media(soma, nlinhas);
		desvio_padrao = desvioPadrao(media_total, nlinhas);
		amplitude = amp(min, max);
		printf("\n\nN%cmero de classes: %d\n\n", 163, nclasses);

		//impressão do histograma

		printf("\n\n  Valor \t  Freq. Absoluta      Freq. Relativa \t   Representa%c%co Gr%cfica\n\n", 135, 198, 160);
		for (int i = 0; i < nclasses; i++)
		{
			printf("%.2f a %.2f \t\t %d \t\t %.1f%% \t\t\t", ((amplitude / nclasses) * i), ((amplitude / nclasses) * (i + 1)), freqAbsoluta(i, nclasses, nlinhas), freqRelativa(i, nclasses, nlinhas));
			for (int j = 0; j < freqAbsoluta(i, nclasses, nlinhas); j++)
				printf("*");
			printf("\n");
		}

		printf("\nM%cdia: %.2f  \t\t Desvio Padr%co: %.2f", 130, media_total, 198, desvio_padrao);
		printf("\n\n\n\n");
		system("pause");

		//fecho do ficheiro e libertação de memória

		delete[]valores;
		fclose(pfile);
	}
}

//cálculo da média

float media(float soma, int nlinhas)
{
	return (soma / nlinhas);
}

//cálculo do desvio padrão

float desvioPadrao(float media, int nlinhas)
{
	float somatorio = 0;
	for (int i = 0; i < nlinhas; i++)
	{
		somatorio += powf((valores[i] - media), 2);
	}
	return sqrtf((somatorio / nlinhas));
}

//cálculo da amplitude

float amp(float min, float max)
{
	return (max - min);
}

//cálculo da frequência absoluta

int freqAbsoluta(int classe, int classes, int nvalores)
{
	int cmin = (amplitude / classes) * classe;
	int cmax = (amplitude / classes) * (classe + 1);
	int count = 0;

	for (int i = 0; i < nvalores; i++)
	{
		if ((valores[i] >= cmin) && (valores[i] < cmax)) count++;
		if ((classe + 1 == classes) && (valores[i] == cmax)) count++;
	}

	return count;
}

//cálculo da frequência relativa

float freqRelativa(int classe, int classes, int nvalores)
{
	return ((freqAbsoluta(classe, classes, nvalores) / (float)nvalores) * 100);
}