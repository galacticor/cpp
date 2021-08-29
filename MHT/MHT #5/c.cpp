#include <iostream>
#include <ctype.h>
#include <cstring>
using namespace std;

string s,t;
int x,y;

int main(){
	cin>>s>>t;
	x=s.length();
	y=t.length();
	for(int i=0;i<=x-1;i++){
		if(isupper(s[i])){
			s[i]=tolower(s[i]);
		}
	}
	for(int i=0;i<=y-1;i++){
		if(isupper(t[i])){
			t[i]=tolower(t[i]);
		}
	}
	
	if(s>t){
		cout<<"1"<<endl;
	}
	else if(s<t){
		cout<<"-1"<<endl;
	}
	else{
		cout<<"0"<<endl;
	}
}
