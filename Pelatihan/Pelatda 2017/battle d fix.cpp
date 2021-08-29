#include <iostream>
#include <cstring>
using namespace std;

bool prime[1000010];
void sieve(int x){
	memset(prime,true,sizeof(prime));
	prime[1]=false;
	for(int i=2;i*i<=x;i++){
		for (int j=i*i;j<=x;j+=i){
			prime[j]=false;
		}
	}
}

int n,a,b,t;
int main(){
	cin>>t;
	n=t+1;
	sieve(n);
	if(n>3){
		cout<<"2"<<endl;
	}
	else cout<<"1"<<endl;
	
	for(int i=2;i<=n;i++){
		if (prime[i]==true){
			cout<<"1"<<" ";
		}
		else cout<<"2"<<" ";
	}
	return 0;
}
