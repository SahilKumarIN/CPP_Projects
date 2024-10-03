#include<iostream>
using namespace std;
int main()
{
    char alphabet;
    
    cout<<"Enter your character";
    cin>>alphabet;
    {
        if(alphabet>='A' && alphabet<='Z')
        cout<<"character is upper case";
        else if(alphabet>='a' && alphabet<='z')
        cout<<"character is in lower case";
        else
        cout<<"invalid character";
    }
return 0;  
}