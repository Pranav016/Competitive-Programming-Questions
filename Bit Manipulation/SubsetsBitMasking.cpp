/*
Question-
Given a char array, print all of its subsets using bit manipulation

Intuition-
Let n be the length of the array.
Total subsets that can be made from the char array - (1<<n)

Run a loop for (1<<n) times and for every iteration,
use the bits of that iteration 'i' to print the
corresponding character from the character array.
Example- 
For i=5 , 5 -> 101
gives out 'ac'

Sample input-
abc
Sample output-
"  "
a
b
ab
c
ac
bc
abc
*/

#include<iostream>
#include<cstring>
using namespace std;

void filterSubstr(char *a,int n){
    int j=0,last_bit=0;
    while(n>0){
        last_bit = (n&1); //last bit of the power
        if(last_bit){//if last bit is set bit
            cout<<a[j];
        }
        j++;
        n = n>>1;
    }
    cout<<endl;
}

void printSubstr(char *a){
    int n = strlen(a);
    for(int i=0;i<(1<<n);i++){// loop runs till n^2 because thats how many subsets will be possible.
        filterSubstr(a,i);
    }
}

int main(){
    char a[100];
    cin>>a;
    printSubstr(a);
}