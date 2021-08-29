#include <iostream>
#include <cstring>
using namespace std;

int isprime[1000010];
void sieve(int x){
	memset(isprime,1,sizeof(isprime));
	isprime[1]=0;
	for(int i=2;i*i<=x;i++){
		for(int j=i*i;j<=x;j+=i){
			isprime[j]=0;
		}
	}
}

int n,t,a,b;

int main(){
	cin>>n;
	sieve(n);
	for(int i=2;i<n;i++){
		a=i;
		b=n-i;
		if ((isprime[a]==0)and(isprime[b]==0)){
			break;
		}
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}
