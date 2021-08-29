#include <iostream>
#include <cstring>
using namespace std;

bool isprime[1000010];
int fact[1000010];

void sieve(int x){
	memset(isprime,true,sizeof(isprime));
	isprime[1]=0;
	for(int i=2;i*i<=x;i++){
		for(int j=i*i;j<=x;j+=i){
			isprime[j]=0;
		}
	}
}

void factor(int n){
	sieve(n);
	int a=2;
	int temp=n;
	while(a<=temp){
		if((isprime[a])and(temp%a==0)){
			fact[a]++;
			temp=temp/a;
		}
		else{
			a++;
		}
	}
	int k=2;
	while (fact[k]==0){
		k++;
	}
	if(fact[k]>1){
		cout<<k<<"^"<<fact[k];
	}else{
		cout<<k;
	}
	for(int i=k+1;i<=n;i++){
		if(fact[i]>0){
				if(fact[i]==1){
					cout<<' '<<"x"<<' '<<i;
				}
				else{
					cout<<' '<<"x"<<' '<<i<<"^"<<fact[i];
				}
		}
	}
}

int main(){
	int n;
	cin>>n;
	factor(n);
	cout<<endl;
	return 0;
}
