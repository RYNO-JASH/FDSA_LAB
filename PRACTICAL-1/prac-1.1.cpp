#include<iostream>
using namespace std;

int main()
{
    int n;
    int hour;
    cout<<"\n Enter Backery item : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\n Enter hour : ";
    cin>>hour;


    hour = hour % n;
    for(int i=0;i<hour;i++)
    {
        int first_element=arr[0];
        for(int k=0;k<n-1;k++)
        {
            arr[k]=arr[k+1];
        }
        arr[n-1]=first_element;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;

}