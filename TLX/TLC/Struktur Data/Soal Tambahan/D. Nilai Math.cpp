#include <bits/stdc++.h>
using namespace std;

int x,y;
char c;

int main(){
	cin>>x>>c>>y;
	if(c=='+'){
		cout<<x+y<<endl;
	}
	if(c=='-'){
		cout<<x-y<<endl;
	}
	if(c=='*'){
		cout<<x*y<<endl;
	}
	if(c=='>'){
		if(x>y){
			cout<<"benar"<<endl;
		}
		else{
			cout<<"salah"<<endl;
		}
	}
	if(c=='<'){
		if(x<y){
			cout<<"benar"<<endl;
		}
		else{
			cout<<"salah"<<endl;
		}
	}
	if(c=='='){
		if(x==y){
			cout<<"benar"<<endl;
		}
		else{
			cout<<"salah"<<endl;
		}
	}
	return 0;
}