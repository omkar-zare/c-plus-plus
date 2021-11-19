/*
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
1 2 3 4 5 6 
1 2 3 4 5 6 7 
1 2 3 4 5 6 7 8 
1 2 3 4 5 6 7 8 9 
1 2 3 4 5 6 7 8 9 10 
*/


#include<bits/stdc++.h>
using namespace std;

void pattern_print(int n){
    if(n == 0){
        return;
    }
    pattern_print(n-1);
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    pattern_print(10);
    return 0;
}