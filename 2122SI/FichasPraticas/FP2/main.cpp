#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void main()
{
	char ficheiro_matriz_a[] = { "matrixA.txt" };
	char ficheiro_matriz_b[] = {"matrixB.txt"};
	char ficheiro_matriz_escrita[] = { "matrixEXIT.txt" };

	Matrix matriz_a, matriz_b, matriz_c;

	if (!matriz_a.ReadFromFile(ficheiro_matriz_a))
	{
		printf("Falhou a leitura da matriz A.\n");
		system("pause");
		exit(1);
	}
	if (!matriz_b.ReadFromFile(ficheiro_matriz_b))
	{
		printf("Falhou a leitura da matriz B.\n");
		system("pause");
		exit(1);
	}

	//Teste de Leitura e Impressao
	printf("Leitura das Matrizes apartir de ficheiros:\nMatriz A:\n");
	matriz_a.Output();
	printf("Matriz B:\n");
	matriz_b.Output();
	//system("pause");

/*	//Teste de Atribuicao, Soma e Multiplicacao;
	printf("Matriz C = Matriz A:\nMatriz C Antes:\n");
	matriz_c = Matrix(2, 2);
	matriz_c.Output();
	matriz_c = matriz_a;
	printf("Matriz C Depois:\n");
	matriz_c.Output();

	printf("Matriz A + Matriz B:\n");
	matriz_c = matriz_a + matriz_b;
	matriz_c.Output();
	printf("Matriz A * Matriz B:\n");
	matriz_c = matriz_a * matriz_b;
	matriz_c.Output();
	matriz_c.SaveToFile(ficheiro_matriz_escrita);
	printf("Resultado foi escrito no ficheiro \n");
	//system("pause");*/

	matriz_b = matriz_a.GetLU();
	printf("Teste LU\n");
	matriz_b.Output();

	/*//Teste de += e *=
    matriz_c = matriz_a;
    printf("Teste +=:\n");
    matriz_c.Output();
    matriz_c += 2; 
    matriz_c.Output();
    //system("pause");

    matriz_c = matriz_a;
    printf("Teste *=:\n");
    matriz_c.Output();
    matriz_c *= 2; 
    matriz_c.Output();
    //system("pause");

    //Teste da matriz transposta
    matriz_c = matriz_a;
    printf("Teste da matriz transposta:\n");
    matriz_c.Output();
    matriz_c.Transpose();
    matriz_c.Output();
    //system("pause");*/
}
