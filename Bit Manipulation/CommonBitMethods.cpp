#include<iostream>
using namespace std;

/*
Theory-
Setting a bit - means that if K-th bit is 0, then set it to 1 and if it is 1 then leave it unchanged.
Clearing a bit - means that if K-th bit is 1, then clear it to 0 and if it is 0 then leave it unchanged.
Toggling a bit - means that if K-th bit is 1, then change it to 0 and if it is 0 then change it to 1.
*/

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

void clearBit(int &n,int i){
    /* Clear Bit the bit at 'i' th position from 1 to 0.
    We can do this by makinga mask of all 1s with ith
    pos as 0 and then AND with the number n to clear the ith bit.
    We have to AND for a specific reason, we cannot do OR. */
    int mask = ~(1<<i); //example- 11111011
    n = n&mask;
}

void updateBit(int &n, int i, int v){
    clearBit(n,i);
    int mask = v<<i;
    n = n|mask;
}

int clearLastIBits(int n, int i){
    // -1 = 111111111
    int mask = (-1<<i); // i is the count of bits getting cleared
    return n&mask;
}

int clearRangeItoJ(int n, int j, int i){
    int mask1 = (~0)<<(j+1);
    int mask2 = (1<<i)-1; //or pow(2,i)-1
    // example for mask2-  1000 -1 = 0111
    int mainMask = mask1|mask2;
    return n&mainMask;
}

int main(){
    int n,i,j;
    cin>>n>>j>>i;
    // cout<<"Get Bit at pos "<<i<<" - "<<getBit(n,i)<<endl;
    // cout<<(getBit(n,i) ? "Set Bit": "Non Set Bit");
    // cout<<"Set Bit at pos "<<i<<" to 1 - "<<setBit(n,i)<<endl;
    // updateBit(n,i,1);
    // cout<<n<<endl;
    // cout<<clearLastIBits(n,i);
    cout<<clearRangeItoJ(n,j,i);
}