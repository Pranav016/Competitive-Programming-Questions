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
/* Set find - Searches the container for an element
equivalent to val and returns an iterator to it if
found, otherwise it returns an iterator to set::end. */
			mp.insert(a[j]);
			j++;
		}
	ans+=((j-i+1)*(j-i))/2; 
	/* this formulae helps us to get the number
	of permutations/ possible subarrays within
	a given range that is between i and j */
	ans=ans%1000000007;
	mp.erase(a[i]);
	}
	cout<<ans;
	return 0;
}