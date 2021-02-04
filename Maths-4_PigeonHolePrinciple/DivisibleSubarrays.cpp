#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

ll a[1000005], freq[1000005];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(freq, 0, sizeof(freq));

        freq[0] = 1; //0 value will come atleast once

        //taking input
        ll sum = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            sum = (sum + n)%n; // we add n to handle case of -ve numbers
            freq[sum]++; //storing the freq of that num in a bucket (0<=num<n)
        }

        ll ans = 0; //number of subsets possible
        for(int i=0;i<n;i++){
            ll m = freq[i];
            ans+=m*(m-1)/2; //mC2 -> number of subarrays possible
        }
        cout<<ans<<endl;
    }
}