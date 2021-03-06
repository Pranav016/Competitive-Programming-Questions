/*
Given an array, the task is to calculate the sum of lengths of contiguous subarrays having all elements distinct

Input Format
An integer n denoting size of array followed by n integers

Constraints
1<=N<=10^5

Output Format
The answer mod 10^9+7

*/

#include<iostream>
#include<map>
using namespace std;

int main(){
    int n, len=0;
    cin>>n;
    map<int, int> m;
    int arr[100000];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(m[arr[j]]!=0){
                break;
            }
            else{
                m[arr[j]]++;
                len+=(j-i+1);
            }
        }
        m.clear();
    }
    cout<<len;
}

/*

Sample Input
3
1 2 3

Sample Output
10

*/
