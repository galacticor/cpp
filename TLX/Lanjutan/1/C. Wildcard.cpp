#include <bits/stdc++.h>
using namespace std;

string s,s1,s2,x;
int asterik,n;
bool pi,p;

int main(){
	cin>>s;
	s1="";
	s2="";
	asterik=10000000;
	for(int i=0;i<=s.length()-1;i++){
		if(s[i]=='*'){
			asterik=i;
		}
		if(i<asterik){
			s1=s1+s[i];
		}
		else if(i>asterik){
			s2=s2+s[i];
		}
	}
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>x;
		p=true;
		for(int i=0;i<asterik;i++){
			if(x[i]!=s1[i]){
				p=false;
			}
		}
		for(int i=0;i<s2.length();i++){
			if(x[x.length()-s2.length()+i]!=s2[i]){
				p=false;
			}
		}
		if(s1.length()>x.length()-s2.length()){
			p=false;
		}
		if(p){
			cout<<x<<endl;
		}
	}
	return 0;
}