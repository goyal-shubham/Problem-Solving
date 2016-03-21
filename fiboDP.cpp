
#include<iostream>

using namespace std;

int * result;

int fiboDP(int num)
{   
    int output;
    
    if( result[num] != 0)
    {
        return result[num];
    }
    if( num <= 2 )
    {
        output = 1;
    }
    else
    {
        output = fiboDP(num - 1) + fiboDP(num - 2);
    }
    
    result[num] = output;
    return output;
}

int getResult( int num)
{
    int result[num];
    for( int i = 0 ; i <= num; i++)
    {
        result[i] = 0;
    }

    return fiboDP( num );
}

int main()
{
    int num;
    cout << "enter the number to final fibonacci " << endl;
    cin >> num;
    result = (int *)malloc( sizeof(int) * num);
    cout << getResult(num) << endl;
}
