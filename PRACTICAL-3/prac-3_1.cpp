#include<iostream>
using namespace std;

void bubble_marks(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(arr[i]>arr[j])
                swap(arr[j],arr[i]);
        }
    }
    cout<<"\n ==== Bubble marks ===="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}

void selection_marks(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
    
    cout<<"\n ==== Selection marks ===="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}

void insertion_marks(int arr[], int n) 
{
    for (int i = 1; i < n; i++)
    {
        int k = arr[i];   
        int j = i - 1;

        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
    cout<<"\n ==== Insertion marks ===="<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i];
    }
}


int main()
{
    int n;
    cout<<"Enter Number of Student : ";
    cin>>n;
    int arr[n];
    cout<<"Enter marks : ";
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    bubble_marks(arr,n);
    selection_marks(arr,n);
    insertion_marks(arr,n);
    return 0;
}