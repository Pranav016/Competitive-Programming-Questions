/*
Question-
The Planet Earth is under a threat from the aliens of the outer space and the Marvel Avengers team is busy fighting against them. Meanwhile, The Incredible Hulk has to defeat an enemy who is N steps above the level where he is standing (assume it as the 0th level). Hulk, because of his incredible jumping ability can take jumps in power of 2. In order to defeat the enemy as quickly as possible he has to reach the Nth step in minimum moves possible. Help Hulk to find the same and contribute in saving the Mother Earth.

Sample Input
3
3
4
5

Sample Output
2
1
2
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, steps = 0;
        cin>>n;
        cout<<(__builtin_popcount(n))<<endl;
    }
}