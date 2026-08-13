#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    string word;
    cout<<"/n Enter word : ";
    getline(cin,word);

    int max_char = 0 ;
    stringstream ss(word);
    string name,longword;
    while(ss>>name)
    {
        if(name.length()>max_char)
        {
            longword=name;
        }
    }
    cout<<"\n Longest Word : "<<longword << endl <<"\n Letter : " <<longword.length();
}