#include <iostream>
#include <cstring>
using namespace std;

int x,j;
string s,r;

int main(){
	cin>>s;
	x=s.length();
	j=0;
	for(int i=0;i<=x-1;i++){
		if(isupper(s[i])){
			s[i]=tolower(s[i]);
		}
		if(s[i]!='a' && s[i]!='i' && s[i]!='u' && s[i]!='e' && s[i]!='o' && s[i]!='y'){
			cout<<"."<<s[i];
		}
	}
	cout<<endl;
	return 0;
}
