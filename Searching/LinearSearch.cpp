#include<iostream>
using namespace std;

int linerSearch(int arr[],int k,int s)
{
    if(s==0)
        return -1;
    for(auto i=0;i<=s;i++)
    {
        if(arr[i]==k)
            return i;
    }
    return -1;
}

int main()
{
    long int n,ele;
    cout<<"Enter the array size:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the the array Elements "<<endl;
    for(auto i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched:";
    cin>>ele;

    int result=linerSearch(arr,ele,n-1);
    if(result==-1)
    {
        cout<<"Element "<<ele<<" not Present!!!"<<endl;
    }
    else{
        cout<<"Element "<<ele<<" found at index "<<result<<endl;
    }
}
