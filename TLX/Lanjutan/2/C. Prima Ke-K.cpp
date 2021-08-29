#include <bits/stdc++.h>
using namespace std;

bool prime[1000010];
long long t,n,k,a[1000010];

void sieve(long long x){
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

int main(){
	cin>>t;
	sieve(1000000);
	k=1;
	for(int i=1;i<=1000000;i++){
		if(prime[i]){
			a[k]=i;
			k++;
		}
	}
	for(int i=1;i<=t;i++){
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}