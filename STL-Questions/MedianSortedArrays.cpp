/*
Problem- We have to find median of sorted arrays.

Median- Element wih 'n' elements smaller than it and 'n' elements greater than it.

Intuition- We put both the arrays in the vector and sorted it. Then we get the middle element. 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> merge;
    int x[1000], y[1000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    for(int i=0;i<n;i++){
        merge.push_back(x[i]);
        merge.push_back(y[i]);
    }
    sort(merge.begin(), merge.end());
    int mid = n-1;
    cout<<merge[mid];
}

/*

Sample input-
5
1 3 5 7 9
2 4 6 8 10

Sample output-
5

*/