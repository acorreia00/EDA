#include "Matrix.h"
void Matrix::Create(int linhas, int cols)
{
	nLinhas = linhas;
	nCols = cols;

	elems = new float*[nLinhas];
	if (elems == NULL) { printf("Nao foi possivel alocar a matriz\n"); return;}
	for (int i = 0; i < linhas; ++i) {
		elems[i] = new float[nCols];
		if (elems[i] == NULL) { printf("Nao foi possivel alocar a linha %d\n", i); return; }
		for (int j = 0; j < nCols; ++j) elems[i][j] = 0;
	}
}
void Matrix::Delete()
{
	if (elems == NULL) return;
	for (int i = 0; i < nLinhas; ++i) delete elems[i];
	delete elems;
}

Matrix::Matrix() { Create(1, 1); }
Matrix::Matrix(int linhas, int cols) { Create(linhas, cols); }
Matrix::Matrix(const Matrix& m1) {
	Create(m1.nLinhas, m1.nCols);
	for (int i = 0; i < nLinhas; ++i) {
		for (int j = 0; j < nLinhas; ++j) elems[i][j] = m1.elems[i][j];
	}
}
Matrix::~Matrix() { Delete(); }

bool Matrix::CanMultiply(const Matrix* pm) {
	return (nCols == pm->nLinhas);
}
bool Matrix::CanAdd(const Matrix* pm) {
	return ((nCols == pm->nCols) && (nLinhas == pm->nLinhas));//se ambas forem verdadeiras, retorna valor 1
}

const Matrix& Matrix::operator = (const Matrix& m1) {
	Delete();
	Create(m1.nLinhas, m1.nCols);
	for (int i = 0; i < nLinhas; ++i) {
		for (int j = 0; j < nCols; ++j) {
			elems[i][j] = m1.elems[i][j];
		}
	}return m1;
}
Matrix Matrix::operator +(const Matrix& m1) {
	if (CanAdd(&m1)) {
		Matrix mres = Matrix(nLinhas, nCols);
		for (int i = 0; i < nLinhas; ++i) {
			for (int j = 0; j < nCols; ++j) mres.elems[i][j] = elems[i][j] + m1.elems[i][j];
		}return mres;
	}
	else {
		printf("\n\nImpossível somar as matrizes\n\n");
		Matrix erro = Matrix();
		return erro;
	}
}
Matrix Matrix::operator *(const Matrix& m1) {
	if (CanMultiply(&m1)) {
		Matrix mres = Matrix(nLinhas, nCols);
		for (int i = 0; i < nLinhas; ++i) {
			for (int j = 0; j < nCols; ++j) {
				int soma = 0;
				for (int k = 0; k < m1.nLinhas; ++k) {
					soma = soma + elems[i][k] * m1.elems[k][j];
				}mres.elems[i][j] = soma;
			}
		}return mres;
	}
	else {
		printf("\n\nImpossível multiplicar as matrizes\n\n");
		Matrix erro = Matrix();
		return erro;
	}
}
const Matrix Matrix::operator +=(int k) {
	Matrix mres = Matrix(nLinhas, nCols);
	for (int i = 0; i < nLinhas; ++i) {
		for (int j = 0; j < nCols; ++j) { mres.elems[i][j]=elems[i][j] + k; }
	}return mres;
}
const Matrix Matrix::operator *=(int k) {
	Matrix mres = Matrix(nLinhas, nCols);
	for (int i = 0; i < nLinhas; ++i) {
		for (int j = 0; j < nCols; ++j) { mres.elems[i][j]=elems[i][j] * k; }
	}return mres;
}

void Matrix::Transpose() {
	Matrix temp = *this;
	Create(nCols, nLinhas);
	for (int i = 0; i < nLinhas; ++i) {
		for (int j = 0; j < nCols; ++j) { elems[i][j] = temp.elems[j][i]; }
	}
}
bool Matrix::ReadFromFile(char const* file_name) {
	FILE* pfile;
	pfile = fopen(file_name, "r");
	if (pfile == NULL) {
		printf("\nErro ao abrir o ficheiro\n");
		return false;
	}else{
		Delete();
		fscanf(pfile, "%f", &nLinhas);
		fscanf(pfile, "%f", &nCols);
		Create(nLinhas, nCols);
		for (int i = 0; i < nLinhas; ++i) {
			for (int j = 0; j < nCols; ++j) {
				fscanf(pfile, "%f", &elems[i][j]);
			}
		}
	}return true;
}
bool Matrix::SaveToFile(char const* file_name) {
	FILE* pfile;
	pfile = fopen(file_name, "wt");
	if (pfile == NULL) {
		printf("\nErro ao criar o ficheiro\n");
		return false;
	}
	else {
		fprintf(pfile, "%d  %d\n", nLinhas, nCols);
		for (int i = 0; i < nLinhas; ++i) {
			for (int j = 0; j < nCols; ++j) fprintf(pfile, "%f ", elems[i][j]);
			fprintf(pfile,"\n");
		}
	}return true;
}
void Matrix::Output() {
	printf("\n\nMatriz %dx%d\n\n", nLinhas, nCols);
	for (int i = 0; i < nLinhas; ++i) {
		for (int j = 0; j < nCols; ++j) { printf("%5.0f", elems[i][j]); }
		printf("\n");
	}
	printf("\n\n");
}
Matrix Matrix::GetLU() {
	if (nCols != nLinhas)
		printf("\nImpossivel, Matriz não é quadrada.\n\n");
	else {

	}
}

