#include <bits/stdc++.h>
using namespace std;

string s;
int res1;

int main(){
	cin>>s;
	if(s.find("Danil")!=-1){
		res1++;
	}
	if(s.find("Olya")!=-1){
		res1++;
	}
	if(s.find("Slava")!=-1){
		res1++;
	}
	if(s.find("Ann")!=-1){
		res1++;
	}
	if(s.find("Nikita")!=-1){
		res1++;
	}

	if(res1==1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}