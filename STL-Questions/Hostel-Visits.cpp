/*
Question-
Dean of MAIT is going to visit Hostels of MAIT. As you know that he is a very busy person so he decided to visit only first "K" nearest Hostels. Hostels are situated in 2D plane. You are given the coordinates of hostels and you have to answer the Rocket distance of Kth nearest hostel from origin ( Dean's place ) .

Input Format
First line of input contains Q Total no. of queries and K There are two types of queries:

first type : 1 x y For query of 1st type, you came to know about the co-ordinates ( x , y ) of newly constructed hostel. second type : 2 For query of 2nd type, you have to output the Rocket distance of Kth nearest hostel till now.

The Dean will always stay at his place ( origin ). It is gauranted that there will be atleast k queries of type 1 before first query of type 2.

Rocket distance between two points ( x2 , y2 ) and ( x1 , y1 ) is defined as (x2 - x1)2 + (y2 - y1)2

*/

#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    priority_queue<long long> hostel;
    int n,k;
    cin>>n>>k;
    long long z;
    int p,x,y;
    while(n!=0){
        cin>>p;
        if(p==1){
            cin>>x>>y;
            z = pow(x,2) + pow(y,2);
            if(hostel.size() == k){
                if(z < hostel.top()){
                    // this condition helps insert the new smallest distance to the hostel so that we can print it
                    hostel.pop();
                    hostel.push(z);
                }
                else{
                    //discard the z value
                }
            }
            else{
                hostel.push(z); //helps insert first k elements
                //first k-1 elements don't matter
            }
        }
        else if(p==2){
            cout<<hostel.top()<<endl;
        }
        n--;
    }
    return 0;
}

/*
Sample input-
9 3
1 10 10
1 9 9
1 -8 -8
2
1 7 7
2
1 6 6 
1 5 5
2

Sample output-
200
162
98
*/