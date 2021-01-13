/* Questions-
Your task is to help Nishant Sort all the strings ( lexicographically ) but if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.
*/


#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a, string b){
	if(a.size() <= b.size() && b.substr(0, a.size())==a){
       return a.size()<=b.size();
    }
    else if(b.size() <= a.size() && a.substr(0, b.size())==b){
        return a.size()>=b.size();
    }
    else{
        return a<b;
    }
}

int main() {
	string s[1000];
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		getline(cin,s[i]);
	}
	sort(s, s+n,compare); //compare function passed here
	for(int i=0;i<n;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}


/*

Sample input-
3
apple
bat
batman

Sample Output-
apple
batman
bat

*/