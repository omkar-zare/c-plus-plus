#include<iostream>
using namespace std;

void swap(int* n,int* m)
{
    int temp;
    temp=*n;
    *n=*m;
    *m=temp;
}

int partition (int arr[], int l, int r)
{
    int pi=arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++)
    {
        if(arr[j]<pi)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[r]);
    return(i+1);
}

void quickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pi=partition(arr,l,r);
        quickSort(arr,pi+1,r);
        quickSort(arr,l,pi-1);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[]={10,40,90,50,80,60,70};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Quick Sort:"<<endl;
    printArray(arr,n);
    quickSort(arr,0,n-1);
    cout<<"After Quick Sort:"<<endl;
    printArray(arr,n);
}
