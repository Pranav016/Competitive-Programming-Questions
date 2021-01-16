/*
Question-
Given n numbers. Print the unique number amongst the list of n random numbers.
*/


#include<iostream>
using namespace std;

int main(){
    int n,ans=0,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        ans = ans ^ x;
    }
    cout<<ans;
}

/*
Sample input-
5
5 2 3 5 2

Sample output-
3
*/