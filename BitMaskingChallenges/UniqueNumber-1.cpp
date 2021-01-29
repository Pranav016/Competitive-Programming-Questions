/*
Question-
We are given an array containg n numbers. All the numbers are present twice except for one number which is only present once. Find the unique number without taking any extra spaces and in linear time. ( Hint - Use Bitwise )

Sample Input
7
1 1 2 2 3 3 4 

Sample Output
4
*/

#include<iostream>
using namespace std;

int main(){
    int n,x;
    int ans = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        ans ^= x;
    }
    cout<<ans;
}