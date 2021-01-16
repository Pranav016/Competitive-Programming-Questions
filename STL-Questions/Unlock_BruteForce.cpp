/*
(Back story of the question is ignored, only main part has been included)
He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. Help him to find the final permutation.

Input Format
First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.
*/


#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[100000], i=0, j=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    while(i<k){
        int max_index = max_element(arr+j, arr+n) - arr;
        if(j!=max_index){
            swap(arr[j], arr[max_index]);
            i++;
        }
        j++;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

/*

Sample Input
5 2
3 4 1 2 5

Sample Output
5 4 3 2 1

*/