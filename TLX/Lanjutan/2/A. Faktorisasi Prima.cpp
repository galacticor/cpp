#include <bits/stdc++.h>
using namespace std;

int a[1000010],temp,n,k;
bool prime[1000010],p[1000010],q;

void sieve(int x){
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	for(int i=1;i*i<=x;i++){
		if(prime[i]){
			for(int j=i*2;j<=x;j+=i){
				prime[j]=false;
			}
		}
	}
}

int main(){
	cin>>n;
	sieve(n);
	temp=n;
	k=2;
	if(prime[n] || n==1){
		cout<<n<<endl;
	}
	else{
		while(temp>1 && k<n){
			if(prime[k] && temp%k==0){
				temp/=k;
				a[k]++;
				p[k]=true;
			}
			else{
				k++;
			}
		}
		k=2;
		while(!q && k<n){
			if(p[k]){
				cout<<k;
				q=true;
			}
			if(a[k]>1){
				cout<<"^"<<a[k];
			}
			k++;
		}
		for(int i=k;i<n;i++){
			if(p[i]){
				cout<<" x "<<i;
			}
			if(a[i]>1){
				cout<<"^"<<a[i];
			}
		}
		cout<<endl;
	}
	return 0;
	
}