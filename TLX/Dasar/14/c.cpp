#include <bits/stdc++.h>
using namespace std;

int x;
string s;
bool p;

bool cekpal(string s,int j){
	if(j>=x){
		return true;
	}
	else{
		if(s[j]==s[s.length()-j-1]){
			j++;
			cekpal(s,j);
		}
		
		else{
			return false;
		}
	}
}

int main(){
	cin>>s;
	x=s.length()/2-1;
	int j=0;
	p=cekpal(s,j);
	if(p){
		cout<<"YA"<<endl;
	}
	else{
		cout<<"BUKAN"<<endl;
	}
	return 0;
}
