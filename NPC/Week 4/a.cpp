#include <bits/stdc++.h>
#include <string>
using namespace std;

string s,k,x;
int t,a;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a;
		if(a==1){
			cin>>k;
			s.insert(0,k);
		}
		if(a==2){
			cin>>k;
			s.insert(s.length(),k);
		}
		if(a==3){
			x=s[0];
			s.insert(s.length(),x);
			s.erase(0,1);
		}
		if(a==4){
			x=s[s.length()-1];
			s.insert(0,x);
			s.erase(s.length()-1,1);
		}
		if(a==5){
			s.erase(0,1);
		}
		if(a==6){
			s.erase(s.length()-1,1);
		}
		if(a==7){
			cout<<s[0]<<endl;
		}
		if(a==8){
			cout<<s[s.length()-1]<<endl;
		}
	}
	if(s.length()==0){
		cout<<"0"<<endl;
	}
	else{
		for(int i=0;i<=s.length()-1;i++){
			cout<<s[i];
		}
	}
	cout<<endl;
	return 0;
}