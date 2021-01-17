#include<bits/stdc++.h>
using namespace std;
int main() {
	set<int>mp;
	int n;
	long long ans=0; 
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int j=0;
	for(int i=0;i<n;i++){
		while(j<n && mp.find(a[j])==mp.end()){
			mp.insert(a[j]);
			j++;
		}
	ans+=((j-i+1)*(j-i))/2;
	ans=ans%1000000007;
	mp.erase(a[i]);
	}
	cout<<ans;
	return 0;
}