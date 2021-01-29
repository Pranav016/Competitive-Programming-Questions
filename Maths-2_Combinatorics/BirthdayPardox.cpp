/*
Question-
Find the number of people required in the room such that probability of people having the same bday is atleast 'p' percent.

Intuition-
- As probability of people not having same bday (1-p) decreases, probability of people having same bday (p) increases.
- If there is one person in the room, then probability of not having same bday is 
(365c1)/365  -> we divide by 365 coz they have 365 choices for birthday date.
- for two persons in the room, probability of not having same bday is 
(365c1)/365 * (354c1)/365  -> because now the second person has 364 choices to choose bday from.

*/

#include<iostream>
using namespace std;

int main(){
    float p; //probability threshold
    /*user wants to know no. of people required
    in the room so that atleast 'p' percent
    people are going to have the same bday*/
    cin>>p;
    if(p==100){ //corner case
        cout<<"366";
        return 0;
    }
    float percentage=100, totalBday=365, bday=365, people=0;
    while(percentage>(100-p)){ //(1-p) is the percentage of people not having same bday
    /*if percentage of people not having same
    bday becomes less than (1-p) then we get
    probability of people having same bday
    Example- if prob required of having same
    bday is 60% or more then prob of not having
    same bday should be 40% or less*/
        people++;
        percentage *= (bday/totalBday);
        bday--;
    }
    cout<<people;
}