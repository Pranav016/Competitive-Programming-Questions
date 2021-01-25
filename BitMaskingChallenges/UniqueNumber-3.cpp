/*
Question-
We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once. Find the unique number. Only use - bitwise operators, and no extra space.

Sample Input-
7
1 1 1 2 2 2 3

Sample Output-
3
*/

#include<iostream>
using namespace std;

int main(){
    int n,x, arr[64]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        int j=0, lastBit;
        while(x>0){
            lastBit = x&1;
            if(lastBit){
                arr[j]++;
            }
            j++;
            x = x>>1;
        }
    }
    for(int i=0;i<64;i++){
        arr[i] = arr[i] % 3;
    }
    //convert binary to decimal
    int p = 1, ans = 0;
    for(int i = 0;i < 64;i++){
        ans += (arr[i]*p);
        p *= 2;
    }
    cout<<ans;
}