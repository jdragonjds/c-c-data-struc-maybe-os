/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0

#define N 9
using namespace std;

bool FindUnassignedLocation (int grid[N][N], int &row, int &col);

bool isSafe (int grid[N][N], int row, int col, int num);

bool UsedInBox (int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
  for (int row = 0; row < 3; row++)
    for (int col = 0; col < 3; col++)
      if (grid[row + boxStartRow][col + boxStartCol] == num)
	  return true;
  return false;
}

bool UsedInCol (int grid[N][N], int col, int num)
{
  for (int row = 0; row < N; row++)
    if (grid[row][col] == num)
      return true;
  return false;
}

bool UsedInRow (int grid[N][N], int row, int num)
{
  for (int col = 0; col < N; col++)
    if (grid[row][col] == num)
      return true;
  return false;
}

bool FindUnassignedLocation (int grid[N][N], int &row, int &col)
{
  for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
      if (grid[row][col] == UNASSIGNED)
	return true;
  return false;
}

bool isSafe (int grid[N][N], int row, int col, int num)
{
     return !UsedInRow (grid, row, num)
    && !UsedInCol (grid, col, num)
    && !UsedInBox (grid, row - row % 3,
		   col - col % 3, num) && grid[row][col] == UNASSIGNED;
}

bool SolveSudoku (int grid[N][N])
{
  int row, col;
 
  if (!FindUnassignedLocation (grid, row, col))
    return true;

  for (int num = 1; num <= 9; num++)
    {

      if (isSafe (grid, row, col, num))
	{
	 
	  grid[row][col] = num;

	  if (SolveSudoku (grid))
	    return true;
//i could use a linked list of 1 to 9 so that i could remove all used no beforehand 
//and add only left unused no in linked list(for a single 3*3 grid) but its heckit let the 
//cpu do the work why bother its take too much time i hate my college 
//it dosent provide anything useful only backtracking was possible at my level
	  grid[row][col] = UNASSIGNED;
	}
    }
  return false;
}

void printGrid (int grid[N][N])
{
  for (int row = 0; row < N; row++)
    {
      for (int col = 0; col < N; col++)
	cout << grid[row][col] << " ";
      cout << endl;
    }
}





int main()
{
    int grid[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
  {5, 2, 0, 0, 0, 0, 0, 0, 0},
  {0, 8, 7, 0, 0, 0, 0, 3, 1},
  {0, 0, 3, 0, 1, 0, 0, 8, 0},
  {9, 0, 0, 8, 6, 3, 0, 0, 5},
  {0, 5, 0, 0, 9, 0, 6, 0, 0},
  {1, 3, 0, 0, 0, 0, 2, 5, 0},
  {0, 0, 0, 0, 0, 0, 0, 7, 4},
  {0, 0, 5, 2, 0, 6, 3, 0, 0}
  };
   if (SolveSudoku (grid) == true)
    printGrid (grid);
  else
    cout << "No solution exists";

  return 0;
}




















