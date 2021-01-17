#include<iostream>
using namespace std;

bool isOdd(int n){
    /*Check if the number is odd or even-
    This can be done by & with 1,
    even numbers would return 0 and
    numbers would return 1 */
    return (n & 1);
}

int getBit(int n, int i){
    /* Check what is the bit at i'th position-
    We create a mask by seft shifting 1 by i positions.
    This mask will give us the ans because anything AND
    with 1 gives number itself.
    1 & 0 = 0
    1 & 1 = 1 */
    int mask = 1<<i;
    int bit = (n & mask)>0?1:0;
    return bit;
}

int setBit(int n, int i){ // we can also send 'n' by reference
    /* We want to set the i'th bit to 1
    Then we do OR of 'n' with 1 left shifted 'i' times.
    1 OR any number = 1
    AND was not used because it would set all
    the other bits to 0 */
    int mask = (1<<i);
    int ans = n|mask;
    return ans;
}

int main(){
    int n,i;
    cin>>n>>i;
    cout<<"Get Bit at pos "<<i<<" - "<<getBit(n,i)<<endl;
    // cout<<(getBit(n,i) ? "Set Bit": "Non Set Bit");
    cout<<"Set Bit at pos "<<i<<" to 1 - "<<setBit(n,i)<<endl;
}