/*
Question-
Given a char array, print out all of its subsets using bit manipulation
Sample input-
abc
Sample output-
"  "
a
b
c
ab
bc
ac
abc
*/

#include<iostream>
#include<cstring>
using namespace std;

void filterSubstr(char *a,int n){
    int j=0,last_bit=0;
    while(n>0){
        last_bit = (n&1);
        if(last_bit){
            cout<<a[j];
        }
        j++;
        n = n>>1;
    }
    cout<<endl;
}

void printSubstr(char *a){
    int n = strlen(a);
    for(int i=0;i<(1<<n);i++){
        filterSubstr(a,i);
    }
}

int main(){
    char a[100];
    cin>>a;
    printSubstr(a);
}