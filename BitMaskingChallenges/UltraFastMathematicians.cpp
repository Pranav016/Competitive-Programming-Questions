/*
Part of the question (story based)-
In his contest he gave the contestants many different pairs of numbers. Each number is made from digits 0 or 1. The contestants should write a new number corresponding to the given pair of numbers. The rule is simple: The i-th digit of the answer is 1 if and only if the i-th digit of the two given numbers differ. In the other case the i-th digit of the answer is 0.

Sample Input-
1
10111 10000

Sample Output-
00111
*/

#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    string s1,s2,ans;
    int t;
    cin>>t;
    while(t--){
        cin>>s1>>s2;
        int len = s1.length();
        for(int i=0;i<len;i++){
            if(s1[i]==s2[i]){
                ans[i] = '0';
            }
            else{
                ans[i] = '1';
            }
        }
        for(int i=0;i<len;i++){
            cout<<ans[i];
        }
        cout<<endl;
    }
}