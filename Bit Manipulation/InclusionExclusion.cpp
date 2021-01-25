/*
Theory-
Inclusion Exclusion principle:
|A1 U A2 U A3 U A4| = |A1|+|A2|+|A3|+|A4|−|A1,2|−|A1,3|−|A1,4|−|A2,3|−|A2,4|−|A3,4|+|A1,2,3|+|A1,2,4|+|A1,3,4|+|A2,3,4|−|A1,2,3,4|

Intuition-
- All the terms with even number of elements are subtracted whereas elements with odd elemenets are to be added.
- Number of subsets possible for n numbers are (2^n-1)
- If we want to make subsets out of an array, we can use bitmasking to create numbers that help make subsets.
Example- [a,b,c] ; 5 = 101 in bits which gives 'ac' subset.
- Total numbers of number divisible by 15 under 1000 = floor(1000/15)

Question-
Find number of elements between 1 to n divisble by all prime numbers less than 20.

Sample input-
5 5 10 12 15 18

Sample output-
4 9 11 14 17
*/

#include<iostream>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    ll primes[] = {2,3,5,7,11,13,17,19};
    while(t--){
        ll n;
        cin>>n;
        ll ans = 0;
        ll subsets = (1<<8)-1;//number of subsets possible are (2^n)-1
        for(ll i=1;i<=subsets;i++){ //We want to iterate upon the number of subsets.
            ll denom = 1ll; //The LL makes the integer literal of type long long, int is only 32 bits
            ll setbits = __builtin_popcount(i); //tells the number of set bits in a number

            for(int j=0;j<=7;j++){ // iterating over all the 8 bits of that number i as well as iterating over primes array
                if(i&(1<<j)){ // we create a mask '(1<<j)' to check if that position has a set bit or not
                    denom *= primes[j]; //we get the denom or the product we wanted to divide n
                }
            }

            if(setbits&1){ //number of elements are odd coz last digit is 1
                ans += (n/denom); //if number of elements are odd then we add to denom
            }
            else{
                ans -= (n/denom);//if number of elements are even then we subtract from denom
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}