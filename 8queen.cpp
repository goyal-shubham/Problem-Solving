
#include<iostream>

#define SIZE 8

using namespace std;

void printSolution(int a[SIZE][SIZE])
{
    for( int i = 0; i < SIZE; i++)
    {
        for( int j = 0; j < SIZE; j++)
        {
            cout << a[i][j] << " ";
        }
        
        cout << endl;
    }
    
}

bool checkCell( int a[SIZE][SIZE] ,int row, int col)
{
    for( int i = 0; i < SIZE; i++)
    {
        if(a[row][i] == 1)
        {
            return false;
        }
    }

    for( int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if(a[i][j] == 1)
        {
            return false;
        }
    }

    for(int i = row, j = col; i < SIZE && j >= 0; i++ , j--)
    {
        if(a[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool findSolution(int a[SIZE][SIZE] , int col)
{
    if( col >= SIZE)
    {
        return true;
    }

    for( int i = 0; i < SIZE; i++)
    {
        if( checkCell(a, i , col) == true )
        {
            a[i][col] = 1;
            if( findSolution(a , col+1) == true)
            {
                return true;
            }

            a[i][col] = 0;
        }
    }
    
    return false;
}

int main()
{
    int a[SIZE][SIZE] = {0};
    if ( findSolution(a, 0) == true)
    {
        printSolution(a);
    }
    cout << endl;
}
