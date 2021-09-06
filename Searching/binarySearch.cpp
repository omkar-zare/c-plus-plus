#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int l,int r)
{
    int pi=arr[r];
    int i=l-1;
    for (int j=l;j<=r-1;j++)
    {
        if(arr[j]<pi)
        {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(arr[i+1],arr[r]);
    return(i+1);
}
void quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pi=partition(arr,l,r);
        quicksort(arr,pi+1,r);
        quicksort(arr,l,pi-1);
    }
}

int binarySearch(int arr[],int k,int l,int r)
{
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]>k)
        {
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int main()
{
    int n,ele;
    cout<<"Enter the array size:";
    cin>>n;
    cout<<"Enter the array Elements:"<<endl;
    int arr[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"Sorted Array Elements:"<<endl;
    for(int i=0;i<=n-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Enter the element to be searched:";
    cin>>ele;
    int result=binarySearch(arr,ele,0,n-1);
    if(result==-1)
    {
        cout<<"Element not Present!!!!!"<<endl;
    }
    else{
        cout<<"Element "<<ele<<" found at index "<<result<<endl;
    }
    return 0;
}
