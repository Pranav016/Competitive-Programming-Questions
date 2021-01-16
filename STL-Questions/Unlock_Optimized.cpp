#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n,k,x;
    vector<int> arr;
    cin>>n>>k;
    unordered_map<int, int> m;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
        m[arr[i]]=i;
    }
    for(int i=0;i<n && k>0;i++){
        int p = n - i;
        if(arr[i] == p){
            //Already correct element
            continue;
        }
        int index = m[p];
        m[arr[i]] = index ;
        m[p] = i;
        swap(arr[i],arr[index]);
        k--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

