/*
Question (Tavas and SaDDas on Codeforces)-
You are given a lucky number n. Lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

If we sort all lucky numbers in increasing order, what's the 1-based index of n?


Intuition-
- Total possibilities of a number of len x having numbers less than it will be:
ans = 2^1 + 2^2 + 2^3 + .... + 2^(x-1) = (2*(2^(x-1)-1)/2 or 2^x-2
- After this, any place that has 7 adds more numbers to the total answer because we can then replace that number and the numbers after it(we started from left of the no.) with 4 or 7.
Example- for number 4474, (1<<pos of 7) more possibilities and they are:
4444
4447

Sample Input
4

Sample Output
1
*/


#include<iostream>
#include<cstring>
#define ll long long
using namespace std;

int main(){
    char a[20];
    cin>>a;
    int len = strlen(a);
    ll ans = 0;

    ans = (1<<len)-2; //this came from a GP series

    for(int i=len-1,pos=0; i>=0; i--,pos++) //we start i from 'len-1' because 0th digit of n will be at len-1 of the char array
    {
        if(a[i]=='7'){ //if it is equal to 7, gives us pow(2,pos) or (1<<pos) more posibilities for numbers.
            ans += (1<<pos);
        }
    }
    cout<<ans+1; //ans is numbers that are occuring before 'n' hence ans+1 is the 1 based index of 'n'
}