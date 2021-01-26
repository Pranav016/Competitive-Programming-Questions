#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, steps = 0;
        cin>>n;
        while(n>0){
            if(n==1){
                steps++;
                break;
            }
            else{
                int k = (int)(log2(n));
                int p = pow(2,k);
                n = n-p;
                steps++;
            }
        }
        cout<<steps<<endl;
    }
}