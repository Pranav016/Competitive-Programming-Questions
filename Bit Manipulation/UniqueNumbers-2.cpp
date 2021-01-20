/*
Question-
Given N numbers, [1 1 2 3 5 2 5 7], we have to find the 2 unique numbers in this list.

Output=
3, 7
*/

#include<iostream>
using namespace std;

int main(){
    int n,arr[100000],x=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        x = x^arr[i]; //XORing all the numbers
    }
    int temp = x; //storing a copy of the xor

    
    //now we get the position of the first set bit from the left
    int pos=0;
    while((temp&1)!=1){
        pos++;
        temp = temp>>1;
    }

    //lets check for numbers having a set bit at position 'pos'
    int mask = 1<<pos;
    int p=0;
    int q=0;
    for(int i=0;i<n;i++){
        if((arr[i]&mask)>0){
        //we xor all the elements having set bit at position 'pos'
            p = p^arr[i];
        }
    }
    //resulant p has our 1 unique element
    q = x^p; // Example- (5^7)^5 = 7
    cout<<min(p,q)<<" "<<max(p,q);
}