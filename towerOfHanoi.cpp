
#include<iostream>
#include<stack>
using namespace std;

int steps = 0;
stack<int> tower1;
stack<int> tower2;
stack<int> tower3;
 
void printStack( stack<int> tower)
{
    while(!tower.empty())
    {
        cout << tower.top() << " ";
        tower.pop();
    }
    cout << endl;
}

void towerOfhanoi(int disk , stack<int>& tower1 , stack<int>& tower3)
{
    steps++;
    if( disk == 1)
    {
        tower3.push(tower1.top());
        tower1.pop();
        steps++;
    }
    else
    {
        towerOfhanoi( disk - 1 , tower1 , tower2);
        tower3.push(tower1.top());
        tower1.pop();
        towerOfhanoi( disk - 1, tower2 , tower3);
    }
}
int main()
{
    int disk;
    cout << "Enter the no. of disks  : " << endl;
    cin >> disk;
    for( int i = disk ; i > 0; i--)
    {
        tower1.push(i);
    }

    towerOfhanoi(disk , tower1 , tower3);
 
    printStack(tower1);
    printStack(tower2);
    printStack(tower3);

    cout << "no. of steps" << steps << endl;
}
