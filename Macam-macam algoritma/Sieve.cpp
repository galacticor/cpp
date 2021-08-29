#include <bits/stdc++.h>
using namespace std;

int a,b,t;
bool prime[10099];

void sieve(int n){
	memset(prime,true,sizeof(prime));
	int count;
	prime[1]=false;
	for (int i=2;i*i<=n;i++){
		if(prime[i]){
			for(int j=i*2;j<=n;j+=i){
				prime[j]=false;
			}
		}
	}
}


int main(){
	sieve(10009);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b;
		for(int j=a;j<=b;j++){
			if(prime[j]){
				cout<<j<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}