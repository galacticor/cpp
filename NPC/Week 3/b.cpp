#include <bits/stdc++.h>
using namespace std;

bool isprime[1000010];
int n;

void sieve(int n){
	memset(isprime,true,sizeof(isprime));
	for(int i=2;i*i<=n;i++){
		for(int j=i;j<=n;j+=i){
			isprime[j]=false;
		}
	}
}

int main(){
	cin>>n;
	sieve(n);
	for(int i=2;i<n;i++){
		if(isprime[i]){
			if(n<2*i){
				cout<<i<<endl;
			}
		}
	}
	return 0;
}


