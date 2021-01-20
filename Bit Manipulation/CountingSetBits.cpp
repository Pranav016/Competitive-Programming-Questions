/*
Given a number N, count the no. of set bits.
N=13
Binary = 1101

Output = 3
*/

#include<iostream>
using namespace std;

int countSetBits(int n){
    //Time complexity = O(logN -1)
    int len = 0;
    while(n>0){
        n&1?len++:NULL;
        n=n>>1;
    }
    return len;
}

int countSetBitsFast(int n){
    //Time complexity = O(No. of set bits)
    // Worst Case = O(logN)
    int ans = 0;
    while(n>0){
        n = n&(n-1);
        //removes the set bits from right to left with each iteration
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<countSetBitsFast(n)<<endl;
    cout<<__builtin_popcount(n); //builtin method to count set bits
}