/*
Question-
We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

Intuiton-
consider pattern of binary values from L to R. We can see that first bit from L to R either changes from 0 to 1 or it stays 1 i.e. if we take the XOR of any two numbers for maximum value their first bit will be fixed which will be same as first bit of XOR of L and R itself.
After observing the technique to get first bit, we can see that if we XOR L and R, the most significant bit of this XOR will tell us the maximum value we can achieve i.e. let XOR of L and R is 1xxx where x can be 0 or 1 then maximum XOR value we can get is 1111 because from L to R we have all possible combination of xxx and it is always possible to choose these bits in such a way from two numbers such that their XOR becomes all 1.

Examples 1:
L = 8 R = 20
L ^ R = (01000) ^ (10100) = (11100)
Now as L ^ R is of form (1xxxx) we
can get maximum XOR as (11111) by
choosing A and B as 15 and 16 (01111
and 10000)

Examples 2:
L = 16 R = 20
L ^ R = (10000) ^ (10100) = (00100)
Now as L ^ R is of form (1xx) we can
get maximum xor as (111) by choosing
A and B as 19 and 20 (10011 and 10100)

So the solution of this problem depends on the value of (L ^ R) only. We will calculate the L^R value first and then from most significant bit of this value, we will add all 1s to get the final result.


Output Format
Print the maximum value of a XOR b

Sample Input
5
6

Sample Output
3
*/


#include<iostream>
#define ll long long
using namespace std;
 
int main(){
    ll x,y,pos=0;
    cin>>x>>y;
    ll intialXOR = x^y;
    while(intialXOR){
        pos++;
        intialXOR = intialXOR>>1;
    }
    ll maxXOR = 0;
    while(pos--){
        maxXOR += (1<<pos);
    }
    cout<<maxXOR;
}