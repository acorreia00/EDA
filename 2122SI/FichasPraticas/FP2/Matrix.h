#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#pragma once

// Definição da classe Matriz que contem as operações 
// tipicas de matrizes
class Matrix {
private:
	float **elems;
	int nLinhas;
	int nCols;
	// Funções privadas
	void Delete();// Apagar a memória dinâmica criada para a matriz
	void Create(int lines, int cols);// Criar a memória dinâmica e inicializar a matriz
public:
	Matrix();// Construtor de defeito
	Matrix(const Matrix& m1);// Construtor Copy
	Matrix(int lines, int cols);
	~Matrix();// Destrutor
	bool CanMultiply(const Matrix* pm);
	bool CanAdd(const Matrix* pm);
	const Matrix& operator = (const Matrix& m1);
	Matrix operator + (const Matrix& m1);
	Matrix operator * (const Matrix& m1);
	const Matrix operator +=(int k); // Soma cada elemento da matriz com o valor k
	const Matrix operator *=(int k); // Multiplica cada elemento da matriz por k
	void Transpose();
	bool ReadFromFile(char const* file_name);
	bool SaveToFile(char const* file_name);
	void Output();
	Matrix GetLU();
};
