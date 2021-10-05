#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*void print(int min, int max) {
	printf("\n\nValor           Freq Absoluta           Freq Relativa           Representacao Grafica");

}*/

int main() {
	FILE* pfile; // Apontador para uma estrutura de um ficheiro
	char nome_ficheiro[] = { "teste.txt" }; // String com o nome do ficheiro
	int* valores; // Apontador para o Array dinâmico que guarda os valores // lidos do ficheiro
	int nlinhas; // Nº de dados que o ficheiro contém
	int nclasses; // Nº de classes do histograma
	int i = 0;
	int max = 0, min = 0, fAbsuluta=0;
	int freqval = 0;
	double media = 0,medsum=0, desv = 0,desvsum=0;
	float fRelativa=0;
	///////////////////////////////////////////////////////////
	// Leitura dos dados de um ficheiro para o array valores
	//

	pfile = fopen(nome_ficheiro, "r"); // Abertura do ficheiro em modo de leitura
	if (pfile == NULL) // Erro na abertura do ficheiro
		printf("Erro na abertura do ficheiro: %s\n", nome_ficheiro);
	else { // Ficheiro aberto sem qualquer problema
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
		}
		freqval = (max - min) / nclasses; // Intervalos de Valores na tabela a apresentar
		media = medsum / nlinhas;  // Media
		for (i = 0; i < nlinhas; i++) {
			desvsum = desvsum + pow((valores[i] - media), 2);  // Parte do Calculo do Desvio Padrao
		}
		desv = sqrt(desvsum / nlinhas);  // Desvio Padrao
		
		//Print de resultados
		printf("\n\nValor            Freq Absoluta           Freq Relativa           Representacao Grafica\n");
		
		for(int c=min;c<max;c=c+freqval) {//print de for
		//printf("teste %d\n",c);
			for(int ctd=c; ctd<c+freqval; ctd++)	{
				for(int ctd1=0; ctd1<nlinhas; ctd1++) {
					if (ctd==valores[ctd1]){
						fAbsuluta++;
					}
				}
			}
			if (c==max-freqval)
						fAbsuluta++;
			fRelativa=((float)fAbsuluta/(float)nlinhas)*100;
			printf("%3d a %3d\t\t%3d\t\t\t%.0f\t\t\t", c, c + freqval, fAbsuluta, fRelativa);
			for(int ctd=0; ctd<fAbsuluta;ctd++) {
				printf("*");
			}
			fAbsuluta=0;
			printf("\n");
		}
		printf("\nMedia:%f\nDesvio Padrao:%f\n\n", media, desv);
		
		//print(min,max);  // Print da Tabela

		delete[] valores; // Libertação da memória ocupada pelo array dinâmico
	}
}
