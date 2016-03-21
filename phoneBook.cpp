#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<string , string> phoneDirectory;
    
    while(1)
    {
        string phoneNum;
        string name;
        cout<<"enter name";
        cin>>name;
        if( name != "quit")
        {
            cout<<"enter phone Number " ;
            cin>>phoneNum;
            phoneDirectory[phoneNum] = name;
        }

        else
        {
            break;
        }
    }

    for ( map<string,string>::iterator it = phoneDirectory.begin() ; it != phoneDirectory.end() ; it++)
    {
        cout<<"name is : "<<it->first<<endl<<"number is: "<<it->second<<endl;
    }
}
