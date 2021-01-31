/*
Intuition-
A^n =   A * (A^(n/2))^2     if n is odd
            (A^(n/2))^2     if n is even

Time complexity = O(log n)
*/

#include<iostream>
using namespace std;

int pow(int a,int n){
    if(n==0){
        return 1;
    }
    // if power is odd
    int subprob = pow(a,n/2);
    if(n&1){
        return a*subprob*subprob; // 5*(5^(n/2))^2
    }
    return subprob*subprob;
}

int main(){
    int a,n;
    cin>>a>>n;
    cout<<pow(a,n);
}