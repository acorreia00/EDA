#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"
#include <stdio.h>


void Matrix::Create(int lines,int cols)
{
	nLines = lines;
	nCols = cols;
	elems = new float* [lines];
	
		
}