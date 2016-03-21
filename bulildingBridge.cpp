

#include<iostream>

#define length 8

using namespace std;

int buildBridge( int *a, int *b)
{
    int buildBridge[length + 1][length + 1];
    for( int i = 0 ; i <= length; i++)
    {
        buildBridge[i][0] = 0;
    }
    for( int j = 1; j <= length; j++)
    {
        buildBridge[0][j] = 0;
    }
    for ( int i = 1; i <= length; i++)
    {
        for ( int j = 1; j <= length ; j++)
        {
            cout << i-1 << "& " << j-1 << ".";
            if ( a[i -1] == b[j - 1])
            {
                buildBridge[i][j] = buildBridge[i-1][j-1] + 1;
            }
            else if (buildBridge[i-1][j] >= buildBridge[j-1][i] )
            {
                buildBridge[i][j] = buildBridge[i-1][j]; 
            }
            else
            {
                buildBridge[i][j] = buildBridge[i][j-1];
            }
            cout << buildBridge[i][j] << '\t';
        }
        cout << endl;
    }
    return buildBridge[length][length];
}

int * corresArray( int * a)
{
    int max = 8;
    int *c = new int[max];

    for( int i = 0; i < max; i++)
    {
        c[i] = -1;
    }
    for( int i = 0; i < max; i++)
    {
        cout << a[i];
        if( i < length)
        {
            c[a[i]]  = i;
        }
        cout << c[i] << '\t';
    }

    cout << endl;
    return c;
}

int main()
{
    int a[length] = {3,6,8,4,2,5,1};
    int b[length] = {2,8,6,5,1,4,3};
    int * d = corresArray(a);
    int * e = corresArray(b);
    cout << "longest bridge is : " << endl <<  buildBridge ( d , e) << endl;
}
