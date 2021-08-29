#include <bits/stdc++.h>
using namespace std;

bool cekpal(string &s){
	int x=s.length();
	if(x<=1){
		return true;
	}
	else{
		if(s[0]==s[x-1]){
			s.erase(0,1);
			s.erase(x-2,1);
			cekpal(s);
		}
		else{
			return false;
		}
	}
}

int x;
string s;
bool p;

int main(){
	cin>>s;
	p=cekpal(s);
	if(p){
		cout<<"YA"<<endl;
	}
	else{
		cout<<"BUKAN"<<endl;
	}
	return 0;
}
