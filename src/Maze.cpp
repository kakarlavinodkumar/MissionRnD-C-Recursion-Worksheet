/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>


int maze_problem(int *maze, int rows, int colums, int x1, int y1, int x2, int y2)
{
	int row_index, col_index, **status, flag = 0;
	status = (int **)malloc(sizeof(int*)*rows);
	for (row_index = 0; row_index < rows; row_index++)
		status[row_index] = (int *)malloc(sizeof(int)*colums);
	for (row_index = 0; row_index < rows; row_index++)
	{
		for (col_index = 0; col_index < colums; col_index++)
			status[row_index][col_index] = 0;
	}
	for (row_index = x1, col_index = y1;; flag = 0)
	{
		if (row_index == x2&&col_index == y2)
			return 1;
		if (flag == 0)
		{
			if (row_index + 1 < rows && *((maze + (row_index + 1)*colums) + col_index) == 1 && status[row_index + 1][col_index] == 0)
			{
				row_index += 1;
				status[row_index][col_index] = 1;
				flag = 1;
			}
			else if (col_index + 1 < colums&&maze[row_index*colums + col_index + 1] == 1 && status[row_index][col_index + 1] == 0)
			{
				col_index += 1;
				status[row_index][col_index] = 1;
				flag = 1;
			}
			else if (row_index > 0 && maze[(row_index - 1)*colums + col_index] == 1 && status[row_index - 1][col_index] == 0)
			{
				row_index -= 1;
				status[row_index][col_index] = 1;
				flag = 1;
			}
			else if (col_index > 0 && maze[row_index*colums + col_index - 1] == 1 && status[row_index][col_index - 1] == 0)
			{
				col_index -= 1;
				status[row_index][col_index] = 1;
				flag = 1;
			}
			else if (row_index > 0 && status[row_index - 1][col_index] == 1)
			{
				status[row_index][col_index] = -1;
				row_index -= 1;
				flag = 1;
			}
			else if (col_index > 0 && status[row_index][col_index - 1] == 1)
			{
				status[row_index][col_index - 1] = -1;
				col_index -= 1;
				flag = 1;
			}
			else
				return 0;
		}
	}
	return 0;
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (maze == NULL || rows <= 0 || columns <= 0 || x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 >= rows || x2 >= rows || y1 >= columns || y2 >= columns)
		return 0;
	return maze_problem(maze, rows, columns, x1, y1, x2, y2);


}