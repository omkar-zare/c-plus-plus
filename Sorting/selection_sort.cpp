#include<iostream>

void Selection_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                min=j;
            }
        }
        int t=arr[i];
        arr[i]=arr[min];
        arr[min]=t;
    }
}

int main()
{
    int n;
    std::cout<<"Enter the Array Size:";
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        std::cin>>arr[i];
    }

    Selection_sort(arr,n);
    std::cout<<"Sorted Array:"<<std::endl;
    for(int i=0;i<=n-1;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}
