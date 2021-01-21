/*
Question-
An array containing n numbers has numbers occuring thrice except for 1 number. Find that number.

Sample Input-
7
1 1 1 2 2 2 3

Sample Output-
3
*/

#include<iostream>
using namespace std;

int main(){
    int n,no, last_bit=0;
    int cnt[64]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>no;
        int j=0;
        while(no>0){
            last_bit = no&1;
            cnt[j] += last_bit;
            j++;
            no = no>>1;
        }
    }
    int p=1, ans=0;
    for(int i=0;i<n;i++){
        cnt[i] = cnt[i]%3;
        ans+=cnt[i]*p;
        p*=2;
    }
    cout<<ans;
}