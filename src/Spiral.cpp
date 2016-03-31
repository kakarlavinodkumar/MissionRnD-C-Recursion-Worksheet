/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
 

int *spiral(int rows, int columns, int **input_array)
{
	int row_index, col_index, row_bound, index, *result, col_bound;
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	result = (int *)malloc(sizeof(int)*(rows*columns));
	for (row_bound = col_bound = index = 0; row_bound < rows - row_bound&&col_bound < columns - col_bound; row_bound++, col_bound++)
	{
		for (col_index = row_bound; col_index < columns - row_bound; col_index++)
			result[index++] = input_array[row_bound][col_index];
		for (row_index = row_bound + 1; row_index < rows - row_bound; row_index++)
			result[index++] = input_array[row_index][columns - row_bound - 1];
		for (col_index = columns - row_bound - 2; col_index >= row_bound; col_index--)
			result[index++] = input_array[rows - row_bound - 1][col_index];
		for (row_index = rows - row_bound - 2; row_index>row_bound; row_index--)
			result[index++] = input_array[row_index][row_bound];
	}
	return result;
}

