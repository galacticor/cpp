#include <bits/stdc++.h>
using namespace std;

int x;
string s;
bool prime[200];

void sieve(int x){
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	for(int i=2;i*i<=x;i++){
		if(prime[i]){
			for(int j=i*2;j<=x;j+=i){
				prime[j]=false;
			}
		}
	}
}

void masukan(string s){
	if(s=="yes"){
		x++;
	}
}

int main(){
	sieve(100);
	for(int i=2;i<=50;i++){
		if(prime[i]){
			cout<<i<<endl;
			cin>>s;
			masukan(s);
		}
	}
	cout<<"4"<<endl;
	cin>>s;
	masukan(s);
	cout<<"9"<<endl;
	cin>>s;
	masukan(s);
	cout<<"25"<<endl;
	cin>>s;
	masukan(s);
	cout<<"49"<<endl;
	cin>>s;
	masukan(s);
	if(x<2){
		cout<<"prime"<<endl;
	}
	else{
		cout<<"composite"<<endl;
	}
	return 0;
}