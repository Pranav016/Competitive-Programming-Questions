/*
Question-
Ravi has been given two strings named string1 and string 2. He is supposed to find the minimum length substring of the string1 which contains all the characters of string2. Help him to find the substring
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);

    int len_s1=s1.size(), len_s2=s2.size();
    int left=0, right=0;
    long int resL=-1, resR=1e9;
    if(len_s2>len_s1){
        cout<<"No String";
        return 0;
    }
    map<char, int> map_s1, map_s2;

    for(auto x:s2){
        map_s2[x]++;
    }

    for( ;right<len_s1;right++){
        map_s1[s1[right]]++;

        bool good=true;

        for(auto x:s2){
            if(map_s1[x]==0 || map_s1[x]<map_s2[x]){
                good=false;
                break;
            }
        }

        if(!good){continue;}

        while(left<len_s1 && left<=right && (map_s2[s1[left]]==0 || map_s1[s1[left]] > map_s2[s1[left]])){
            map_s1[s1[left]]--;
            if(map_s1[s1[left]] == 0){map_s1.erase(s1[left]);}
            left++;
        }

        if(resR - resL +1 > right - left +1){
            resR=right;
            resL=left;
        }
    }
    if(resL==-1){
        cout<<"No String";
        return 0;
    }
    for(int i=resL;i<=resR;i++){
        cout<<s1[i];
    }
}

/*
Sample Input- 
qwerty asdfgh qazxsw
qas

Sample Output- 
qazxs
*/
