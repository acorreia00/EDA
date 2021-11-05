#define _SRT_SECURE_NO_WARNINGS
#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

void Matrix::Delete()
{
	for (int i = 0; i < nLines; i++)
		delete[]elems[i];
	delete[]elems;
}

void Matrix::Create(int lines, int cols)
{
	nLines = lines;
	nCols = cols;
	elems = new float * [nLines];
	for (int i = 0; i < nLines; i++)
	{
		elems[i] = new float [nCols];
		for (int j = 0; j < nCols; j++)
		{
			elems[i][j] = 0;
		}
	}
}

Matrix::Matrix()
{
	elems = NULL;
	nLines = 0;
	nCols = 0;
}

Matrix::Matrix(const Matrix& m1)
{
	Create(m1.nLines, m1.nCols);
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			elems[i][j] = m1.elems[i][j];
		}
	}
}

Matrix::Matrix(int lines, int cols)
{
	Create(lines, cols);
}

Matrix::~Matrix()
{
	Delete();
}

bool Matrix::CanMultiply(const Matrix* pm)
{
	return nCols == pm->nLines;
}

bool Matrix::CanAdd(const Matrix* pm)
{
	return nCols == pm->nCols && nLines == pm->nLines;
}

const Matrix& Matrix::operator=(const Matrix& m1)
{
	Create(m1.nLines, m1.nCols);
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			elems[i][j] = m1.elems[i][j];
		}
	}

	return *this;
}

Matrix Matrix::operator+(const Matrix& m1)
{
	Matrix result(m1.nLines, m1.nCols);
	if (CanAdd(&m1))
	{
		for (int i = 0; i < nLines; i++)
		{
			for (int j = 0; j < nCols; j++)
			{
				result.elems[i][j] = elems[i][j] + m1.elems[i][j];
			}
		}
	}
	else
	{
		printf("\nA soma nao eh possivel");
	}

	return result;
}

Matrix Matrix::operator*(const Matrix& m1)
{
        Matrix result(nCols, m1.nLines);
		if (CanMultiply(&m1)) 
		{
			for (int i = 0; i < result.nLines; i++)
			{
				for (int j = 0; j < result.nCols; j++)
				{
					for (int k = 0; k < result.nCols; k++)
					{
						result.elems[i][j] += elems[i][k] * m1.elems[k][j];
					}
				}
			}
		}
		else
		{
			printf("\nO produto nao eh possivel");
		}
		return result;
}

const Matrix& Matrix::operator+=(int k)
{
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			elems[i][j] = elems[i][j] + k;
		}
	}
	return *this;
}

const Matrix& Matrix::operator*=(int k)
{
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			elems[i][j] = elems[i][j] * k;
		}
	}
	return *this;
}

void Matrix::Transpose()
{
	Matrix temp;
	temp = *this;
	Delete();
	Create(temp.nCols, temp.nLines);
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			elems[i][j] = temp.elems[j][i];
		}
	}
}

bool Matrix::ReadFromFile(char* file_name)
{
	FILE* file;
	fopen_s(&file, file_name, "r");
	if (!file) return false;
	fscanf_s(file, "%d", &nLines);
	fscanf_s(file, "%d", &nCols);
	Create(nLines, nCols);
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
			fscanf_s(file, "%f", &elems[i][j]);
	}
	fclose(file);
	return true;
}

bool Matrix::SaveToFile(char* file_name)
{
	FILE* file;
	fopen_s(&file, file_name, "w");
	if (!file) return false;
	fprintf_s(file, "%d %d \n", nLines, nCols);
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
			fprintf_s(file, "%f \n", elems[i][j]);
	}
	fclose(file);
	return true;
}

void Matrix::Output()
{
	for (int i = 0; i < nLines; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			printf("%g  ", elems[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

Matrix Matrix::GetLU()
{
	Matrix U;
	U = *this;
	float f;
	//Create(U.nCols, U.nLines);
	for (int i = 0;i <= nLines - 2;i++) {
		for (int j = i + 1;j <= nLines - 1;j++) {
			//elems[j][i] = U.elems[j][i] / U.elems[i][i];
			f = U.elems[j][i] / U.elems[i][i];
			for (int m = i + 1;m < nCols;m++) {
				U.elems[j][m] = U.elems[j][m] - U.elems[i][m] * f;
			}
			U.elems[j][i]=f;
		}
	}
	return U;
}
