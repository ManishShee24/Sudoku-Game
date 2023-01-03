// Solve Sudoku Game using Backtracking

#include<bits/stdc++.h>
#define N 9
using namespace std;

bool isSafe(int grid[N][N], int row, int col, int n)  //check valid Sudoku
{
    for(int i = 0;i < N; i++)
    {
        if(grid[row][i] == n)  // either col will varry,and it equals to the number
            return false;

        if(grid[i][col] == n)  //or row will varry,and it equals to the number
            return false;
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for(int i = 0;i < N / 3; i++)
    {
        for(int j = 0;j < N / 3; j++)
        {
            if(grid[i + startRow][j + startCol] == n)  //If it equals to the number
                return false;
        }
    }
    return true;
}

bool solveSudoku(int grid[N][N], int row, int col)
{
    if(row == N - 1 && col == N)  //If we reached 8th row and 9th col
        return true;

    if(col == N)  //If we reached only 9th col
    {
        row++;
        col = 0;  //col becomes 0
    }

    if(grid[row][col])  //If element is greater than 0
        return solveSudoku(grid,row,col + 1);

    for(int num = 1;num <= N; num++)
    {
        if(isSafe(grid,row,col,num))   //If the function returns true
        {
            grid[row][col] = num;
            if(solveSudoku(grid,row,col + 1))
                return true;
        }
        grid[row][col] = 0;   //at last the final element is 0
    }
    return false;  //otherwise returns false
}
int main()
{
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if(solveSudoku(grid, 0, 0))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "No solution  exists." << endl;

    return 0;
}
