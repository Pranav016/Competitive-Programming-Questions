/*
Question-
We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space. ( Hint - Use Bitwise )

Sample Input
4
3 1 2 1

Sample Output
2 3
*/

#include<iostream>
using namespace std;

int main(){
    int n,x,ans = 0, arr[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
        ans ^= x;
    }
    int pos = 0,temp = ans;
    while((temp&1)!=1){ //looking for first set bit from the left
        pos++;
    }
    int p = 0;
    for(int i=0;i<n;i++){
        if((arr[i]&(1<<pos))==1){
            p ^= arr[i];    
        }
    }
    int q = ans ^ p;
    cout<<min(p,q)<<" "<<max(p,q);
}