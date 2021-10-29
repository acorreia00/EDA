#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"
#include <stdio.h>


void Matrix::Delete(){

	if (elems == NULL) return;

	for (int i = 0; i < nLines; ++i) {
		delete[] elems[i];
	}

	delete[] elems;

}

void Matrix::Create(int lines, int cols){

	nLines = lines;
	nCols = cols;

	elems = new int* [nLines];         // Aloca vetor de apontadores
	if (elems == NULL) {
		printf("Nao foi possivel alocar a matriz\n");
		return;
	}

	for (int i = 0; i < nLines; ++i) {
		elems[i] = new int[nCols];  // Aloca cada uma das linhas da matriz como se fosse um vector independente
		if (elems[i] == NULL) {
			printf("Nao foi possivel alocar a linha %d da matriz\n", i);
			return;
		}
	}

	for (int i = 0; i < nLines; ++i) {
		for (int j = 0; j < nCols; ++j) {
			elems[i][j] = 0;
		}
	}

}

Matrix::Matrix() {

	Create(1, 1);

}

Matrix::Matrix(const Matrix& m1) {

	Create(m1.nLines, m1.nCols);
	for (int i = 0; i < nLines; i++){
		for (int j = 0; j < nCols; j++){
			elems[i][j] = m1.elems[i][j];
		}
	}
}

Matrix::Matrix(int lines, int cols) {

	Create(lines, cols);

}

Matrix::~Matrix() {

	Delete();

}

void Matrix::Output(){

	printf("Dimensao = %d x %d\n", nLines, nCols);
	for (int i = 0; i < nLines; ++i) {
		for (int j = 0; j < nCols; ++j) {
			printf("%6d", elems[i][j]);
		}
		printf("\n");
	}

}
