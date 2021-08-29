#include <bits/stdc++.h>
using namespace std;

int prime[1000000005],t,memo[1000000005];

void sieve(int n){
	int prime[n+1];
	memset(prime,1,sizeof(prime));
	for (int i=2;i*i<=n;i++){
		if(prime[i]==1){
			for(int j=i*2;j<=n;j+=i){
				prime[j]=0;
			}
		}
	}
}

int rec(int co,int a){
	if(a==4 && a==6){
		return 1;
	}
	else if((a==0 && a==1 && a==9 && a==2 && a==3 && a==5 && a==7 && a==9 && a==11) || (co==1 && prime[a]==0){
		return 0;
	}
	else if(memo[a]!=0){
		return memo[a];
	}
	else{
		for(int x=4;x<=a;x++){
			memo[a]=memo[a]+rec(x)+rec(a-x);;
		}
	}
	return memo[a];
}

int main(){
	cin>>t;
	sieve(1000000000);
	int n;
	for(int i=1;i<=t;i++){
		cin>>n;
		rec(n);
	}
}