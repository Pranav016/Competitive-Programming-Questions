/*
Question-
Sequence (ai) of natural numbers is defined as follows:

   ai = bi (for i <= k)
   ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute an for given n and output it modulo 109.

In other words = (Given first k terms of a series, find the nth term such that n could be greater than or less than k.)

Problem- SEQ from Spoj

Input:
3 
3 
5 8 2 
32 54 6 
2 
3 
1 2 3 
4 5 6 
6 
3 
24 354 6 
56 57 465 
98765432

Output:
8 
714 
257599514
*/

#include<iostream>
#include<vector>
using namespace std;

#define ll long long
#define MOD 1000000000

ll k;
vector<ll> a, b, c;

vector<vector<ll> > multiply(vector<vector<ll> > A, vector<vector<ll> > B){
    //storing result
    vector<vector<ll> > C(k+1, vector<ll>(k+1));

    //logic to multiply matrices
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int x=1;x<=k;x++){
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MOD) %MOD; // to prevent overflow

            }
        }
    }
    return C;
}

vector<vector<ll> > pow(vector<vector<ll> > A, ll p){
    if(p==1){
        return A;
    }
    
    // if power is odd
    if(p&1){
        return multiply(A, pow(A,p-1));
    }
    vector<vector<ll> > X = pow(A,p/2);
    return multiply(X,X);
}

ll compute(ll n){
    // base case
    if(n==0){
        return 0; 
    }
    
    if(n<=k){
        return b[n-1];
    }

    //otherwise use matrix exponentiation
    vector<ll> F1(k+1);

    //indexing from 1
    //Step-1
    for(int i=1;i<=k;i++){
        F1[i] = b[i-1];
    }

    //Step-2 Transformation matrix
    vector<vector<ll> > T(k+1, vector<ll>(k+1));

    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i<k){
                //fill 0s and 1s
                if(j==i+1){
                    T[i][j] = 1;
                }
                else{
                    T[i][j] = 0;
                }
            }
            else{
                T[i][j] = c[k-j];
            }
        }
    }

    //Step-3
    T = pow(T, n-1); //calculating T^(n-1)

    //Step-4
    ll res = 0;
    for(int i=1;i<=k;i++){
        res = (res + (T[1][i] * F1[i]) %MOD) %MOD; //multiplying first row of T^(n-1) matrix and F1 matrix
    }
    return res;
}

int main(){
    ll t,n,num;
    cin>>t;
    while(t--){
        cin>>k;
        //input vector F1
        for(int i=0;i<k;i++){
            cin>>num;
            b.push_back(num);
        }
        //input their coefficients
        for(int i=0;i<k;i++){
            cin>>num;
            c.push_back(num);
        }
        //the value of n
        cin>>n;
        cout<<compute(n)<<endl; //finding nth value of the series

        b.clear();
        c.clear();
    }
    return 0;
}