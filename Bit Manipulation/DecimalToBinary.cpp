/*
Question-
Given a number N, print its binary representation.
*/

#include<iostream>
using namespace std;

int decimalToBinary(int n){
    int ans = 0, i = 1, lastBit;
    while(n>0){
        lastBit = n&1;
        n=n>>1;
        ans+=lastBit*i;
        i*=10;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<decimalToBinary(n);
}