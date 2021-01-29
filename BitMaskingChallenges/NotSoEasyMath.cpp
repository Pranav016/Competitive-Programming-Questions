/*
Question (Storyline excluded)-
Ironman and Thor got into a fight and Ironman challenged Thor to find out the number of numbers between 1 and n which are divisible by any of the prime numbers less than 20

Theory-
We have to calculate the union of the numbers divisbile by each of the primes numbers under 20. For this we can use inclusion-exclusion principle.

* For complete explanation refer to inclusion-exclusion problem in Bit manipulation section.

Sample Input
5
5
10
12
15
18

Sample Output
4
9
11
14
17
*/

#include<iostream>
#define ll long long
using namespace std;

int main() {
    int primes[] = {2,3,5,7,11,13,17,19};
    ll t;
    cin>>t;
    while(t--){
        ll n,ans = 0;
        cin>>n;
        ll subsets = (1<<8)-1; //number of subsets possible for 8 numbers
        for(int i=1;i<=subsets;i++){
            ll denom = 1ll;
            ll setbits = __builtin_popcount(i);
            for(int j=0;j<8;j++){ //iterating over te 8 bits of 'i'
                if(i&(1<<j)){
                    denom *= primes[j];
                }
            }
            if(setbits&1){
                ans += (n/denom);
            }
            else{
                ans -= (n/denom);
            }
        }
        cout<<ans<<endl;
    }

	return 0;
}