
#include<iostream>

#define n 7

using namespace std;

void makeChange(int * dominations, int c , int types , int * notes)
{
    if( c == 0 )
    {
        return;
    }

    notes[types - 1]  = c / dominations[types-1] ;
    if ( notes[types - 1]  > 0)
    {
        int used = dominations[types-1] * notes[types - 1];
        c = c - used;
    }
    
    makeChange(dominations , c , types-1 , notes);
}

int main()
{
    int dominations[n] = { 1, 2, 5 ,10 ,20 ,50 ,100 };
    int notes[n] = { 0,0,0,0,0,0,0};
    int amount;
    cout << "enter the total amount ";
    cin >> amount;
    makeChange(dominations , amount , n , notes);
    for ( int i = 0; i < n; i++)
    {
        cout << dominations[i] << "-> " << notes[i] << endl;
    }
}
