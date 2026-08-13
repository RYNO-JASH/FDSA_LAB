#include<iostream>
#include<vector>
using namespace std;

int linearFindCar(vector<int> &arr , int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int recursivelinearFindCar(vector<int> &arr , int n, int key, int i)
{
    if(n==i)
        return -1;
    if(arr[i]==key)
    {
        return i;
    }
    return recursivelinearFindCar(arr,n,key,i+1);
}

int main()
{
    int n,key=0,type;
    cout<<"Enter num of vehicles : ";
    cin>>n;
    vector<int> arr(n);

    for(int i = 0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter type for normal linear or recursive linear (1 or 2)";
    cin>>type;
    if(type==1 || type ==2)
    {
        if(type==1)
        {
            cout<<"Enter the num ! to search ? ";
            cin>>key;
            int value = linearFindCar(arr,n,key);
            if(value>=0)
                cout<<"Found Car = "<<arr[value]<<endl<<"At : "<<value+1<<" position"<<endl;
            else
                cout<<"Car not found !!! "<<endl;
        }
        if(type==2)
        {
            cout<<"Enter the num ! to search ? ";
            cin>>key;
            int value = recursivelinearFindCar(arr,n,key,0);
            if(value>=0)
                cout<<"Found Car = "<<arr[value]<<endl<<"At : "<<value+1<<" position"<<endl;
            else
                cout<<"Car not found !!! "<<endl;
        }
    }
    else
        cout<<"Invalid input "<<endl;
    return 0;
}