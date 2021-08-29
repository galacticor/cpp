#include <iostream>
#include <ctype.h>
#include <cstring>
using namespace std;

string s;

int main(){
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(isupper(s[i])){
			s[i]=tolower(s[i]);
		}
		else{
			if(islower(s[i])){
				s[i]=toupper(s[i]);
			}
		}
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}
