#include<bits/stdc++.h>
using namespace std;

int sum_n(int n){
    if(n == 1){
        return 1;
    }
    
    int left=sum_n(n-1);
    return left*n;
}

int main(){
    cout<<"Factorial of 10! ="<<sum_n(10)<<endl;
    return 0;
}