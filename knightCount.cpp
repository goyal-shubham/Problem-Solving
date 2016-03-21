
#include<iostream>

using namespace std;

void displayBoard( int n , int board[][])
{
    for( int i = 0; i < n; i++)
    {
        for( int j = 0; j< n; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }
}

void markOthers( int row, int col)
{
    if( row - 2 > 0 && col - 1 > 0 col + 1 < n)
    {
        a[row-2][col-1] = 0;
        a[row-2][col+1] = 0;
    }
    
    if( row - 1 > 0 && col - 2 > 0)
    {
        a[row-2][col-1] = 0;
        if( col + 1 < n)
        {
            a[row-2][col+1] = 0;
        }
    }
    
    if( row - 2 > 0 && col - 1 > 0)
    {
        a[row-2][col-1] = 0;
        if( col + 1 < n)
        {
            a[row-2][col+1] = 0;
        }
    }
    
    if( row - 2 > 0 && col - 1 > 0)
    {
        a[row-2][col-1] = 0;
        if( col + 1 < n)
        {
            a[row-2][col+1] = 0;
        }
    }
}

int countKnight(int n, int board[][])
{
    int count = 0;
    for( int i = 0; i < n; i++)
    {
        for( int j = 0; j < n; j++)
        {
            if( board[i][j] == -1)
            {
                board[i][j] = 1;
                markOthers(i , j);
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "enter size n of n*n chess board \t";
    cin >> n;
    board[n][n] = {-1};
    cout << "maximum no. of knights is " << countKnight(board , n) << endl;
    displayBoard(board , n);
}
