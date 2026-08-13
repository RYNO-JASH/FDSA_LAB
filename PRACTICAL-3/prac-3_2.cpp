#include<iostream>
#include<vector>

using namespace std;

void selectioncolour(vector<int>c , int n)
{   for(int i = 0;i<n-1;i++)
    {
        int no = i;
        for(int j =i+1 ;j<n;j++)
        {
            if(c[j]< c[no])
            {
                no=j;
            }
            
        }
        swap(c[i],c[no]);
    }
    for(int f : c)
    {
        cout<<f << " ";
    }
}
int main()
{
    vector<int>c = {1,0,1,2,1,0,2,1};

    selectioncolour(c,c.size());
}