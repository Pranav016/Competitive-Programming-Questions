/*
Question-
We have find 'a' power 'n' using bit manipulation.

Intuition-
example- 3^2
- Let ans=1
- 2 can be represented as 010 in bits.
- 0th bit gets multiplied by 3 and 1st bit with 3^2 and so on.
- take the last bit of the power. If its a set bit, then only multiply 'a' with ans
return ans

Sample input- 3 2
Output- 9
*/

#include<iostream>
using namespace std;

int main(){
    int a,n,ans=1;
    cin>>a>>n;
    while(n>0){ //'n' here is the power
        int last_bit = (n&1); //taking out the last bit
        if(last_bit){
        //if the last bit is a set bit then we multiply with ans
        ans *= a;
        }
        //here we update 'a'
        a=a*a;
        n=n>>1;
    }
    cout<<ans;
}