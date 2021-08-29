#include <bits/stdc++.h>
using namespace std;

string s,t;
int x;
bool p;

int main(){
	cin>>s;
	cin>>t;
	p=true;
	for(int i=0;i<t.length();i++){
		x=s.find(t[i]);
		if(x!=-1){
			s.erase(x,1);
		}
		else{
			p=false;
			break;
		}
	}
	if(p){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
