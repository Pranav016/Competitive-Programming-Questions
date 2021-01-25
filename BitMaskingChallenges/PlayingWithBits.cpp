/*
Prateek Bhayia likes to play with bits. One day Prateek bhayia decides to assign a task to his student Sanya. You have help Sanya to complete this task. Task is as follows - Prateek Bhayia gives Q queries each query containing two integers a and b. Your task is to count the no of set-bits in for all numbers between a and b (both inclusive)

Sample Input
2
1 1
10 15

Sample Output
1
17
*/

#include<iostream>
using namespace std;
int main() {
	int t,x,y;
	cin>>t;
	while(t--){
		int ans = 0;
		cin>>x>>y;
		for(int i=x;i<=y;i++){
			ans += __builtin_popcount(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}