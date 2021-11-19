#include<bits/stdc++.h>
using namespace std;
#define ll long long

int sum_digits(ll n){
    if(n == 0){
        return 0;
    }
    int last_digit= n%10;
    ll remaining= n/10;
    return sum_digits(remaining)+last_digit;
}

int main(){
    cout<<"Sum_of_specified_digits :"<<sum_digits(14375875834520432)<<endl;  //1+4+3+7+5+8+7+5+8+3+4+5+2+0+4+3+2=71
    return 0;
}