#include<iostream>
#include<vector>

using namespace std;
int binaryFindBookCode(vector<int> &arr,int n,int key)
{
    int low = 0 , high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}
int recursivebinaryFindBookCode(vector<int> &arr,int low,int high,int key)
{
    if(low>high)
        return -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<=key)
            return recursivebinaryFindBookCode(arr,mid+1,high,key);
        else
            return recursivebinaryFindBookCode(arr,low,mid-1,key);
    }
}


int main()
{
    int n,key=0,type;
    cout<<"Enter num of Book Size : ";
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
            int value = binaryFindBookCode(arr,n,key);
            if(value>=0)
                cout<<"Found Book Code = "<<arr[value]<<endl<<"At : "<<value+1<<" position"<<endl;
            else
                cout<<"Book Code not found !!! "<<endl;
        }
        if(type==2)
        {
            cout<<"Enter the num ! to search ? ";
            cin>>key;
            int value = recursivebinaryFindBookCode(arr,0,n-1,key);
            if(value>=0)
                cout<<"Found Book Code = "<<arr[value]<<endl<<"At : "<<value+1<<" position"<<endl;
            else
                cout<<"Book Code not found !!! "<<endl;
        }
    }
    else
        cout<<"Invalid input "<<endl;
        
    return 0 ;
}