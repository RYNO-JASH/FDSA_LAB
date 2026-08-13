#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map <int,int> lib;
    
    int n,id;
    cout<<"\n Enter no of books : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\n ID : ";
        cin>>id;

        lib[id]++;
    }
    for(auto &x : lib)
    {
        if(x.second>1)
        {
            cout<<"\n id : "<<x.first;
        }
    }

}