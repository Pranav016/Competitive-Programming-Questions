/*
Set all bits between i and j in N equal to M. (M becomes a substring located at i starting from j)

Example-
N = 1000000000
M = 10101
i = 2 , j = 6

Output-
1001010100
*/

#include<iostream>
using namespace std;

int clearRangeItoJ(int n, int j, int i){
    int mask1 = (~0)<<(j+1);
    int mask2 = (1<<i)-1;
    int mainMask = mask1|mask2;
    return n&mainMask;
}

int replaceBits(int n,int m, int j, int i){
    int ans = clearRangeItoJ(n,j,i);
    int newM = m<<i;
    return ans|newM; 
}

int main(){
    int n, m, j, i;
    cin>>n>>m>>j>>i;
    cout<<replaceBits(n,m,j,i);
}