#include <bits/stdc++.h>
using namespace std;

int res,xa,xb,indxa;
string s;

int main(){
	cin>>s;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]=='a'){
			indxa=i;
			xa++;
		}
		if(s[i]=='b'){
			xb++;
		}
	}
	res=s.length()-indxa;
	if(xb==s.length() || xa==s.length()){
		cout<<"0"<<endl;
	}
	else{
		cout<<res<<endl;
	}
}