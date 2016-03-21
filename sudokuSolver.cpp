
#include<iostream>
#include<math.h>
#define n 3
#define SIZE n * n

using namespace std;

void printSudoku( int **a)
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

bool checkCol( int **a , int col , int num)
{
    for( int i = 0; i < SIZE; i++)
    {
      if(a[i][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool checkCell(int **a , int row , int col, int num )
{
    
        for(int i = 0; i < SIZE; i++)
        {
            if(a[i][col] == num)
            {
                return true;
            }
            if(a[row][i] == num)
            {
                return true;
            }
        } 
        row = (row / n) * n;
        col = (col / n) * n;
        for( int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if ( a[row+i][col+j] == num )
                {
                    return true;
                }
            }
        }
        
    return false;
}

bool insert(int **a , int row, int col)
{   

    if( row == SIZE)
    {
        row = 0;
        col++;
    }
    if( col >= SIZE )
    {
        return true;
    }
    
    else
    {
        for( int num = 1; num <= SIZE; num++)
        {
            if( a[row][col] > 0 )
            {
                if (insert(a, row + 1 , col) == true)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            if( checkCell(a, row , col , num) == false)
            {    
                
                a[row][col] = num;
                printSudoku(a);
                cout << endl << endl;    
                if(insert(a, row + 1 , col ) == true )
                {
                    return true;
                }
                a[row][col] = 0;
            }
        }  
    return false;
    }
}

int main()
{
    int **a;
    a = (int **)malloc ( sizeof(int *) * SIZE);
    for( int i = 0; i < SIZE; i++)
    {    
        a[i] = (int *)malloc( sizeof(int) * SIZE);
    }
    for( int i = 0; i < SIZE; i++)
    {
        for( int j = 0; j < SIZE; j++)
        {
            a[i][j] = 0;
        }
    }
    a[0][2] = 6;
    a[0][8] = 4;
    a[1][3] = 8;
    a[1][4] = 6;
    a[1][6] = 7;
    a[1][7] = 3;
    a[2][1] = 4;
    a[2][3] = 3;
    a[2][4] = 5;
    a[2][8] = 2;
    a[3][0] = 1;
    a[3][1] = 7;
    a[3][3] = 4;
    a[3][6] = 6;
    a[4][1] = 9;
    a[4][7] = 8;
    a[5][2] = 8;
    a[5][5] = 6;
    a[5][7] = 1;
    a[5][8] = 7;
    a[6][0] = 2;
    a[8][0] = 8;
    a[7][1] = 6;
    a[7][2] = 7;
    a[6][4] = 8;
    a[6][7] = 4;
    a[7][4] = 4;
    a[7][5] = 3;
    a[8][6] = 3;
    a[6][5] = 1;
    
    printSudoku(a);
    cout << endl;
    if( insert(a, 0 , 0 ) == true)
    {
        printSudoku(a);
    }
    else
    {
        cout << " solution does not exist";
    }
}
