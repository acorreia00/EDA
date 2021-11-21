#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <locale.h>
#include <math.h>
#include "Matrix.h"

int main(){
	setlocale(LC_ALL, "pt_PT");
	setlocale(LC_NUMERIC, "C");
	Matrix A;
	A.ReadFromFile("matrix1.txt");
	A.Output();
	Matrix B;
	B.ReadFromFile("matrix2.txt");
	B.Output();
	Matrix C;
	C = (A *= 5);
	C.Output();
	C.Transpose();



	system("pause");
	return 0;
}