#include <bits/stdc++.h>
using namespace std;

long long n,memo[200],temp,ans;

long long f(int x){
	if(x==1){
		return 2;
	}
	else if(x==2){
		return 3;
	}
	else if(memo[x]!=0){
		return memo[x];
	}
	else{
		memo[x]=(f(x-1)+f(x-2))%1000000007;
	}
	return memo[x];
}

void power(int x){
	for(int i=1;i<=x;i++){
		temp=(temp*2)%1000000007;
	}
}

int main(){
	cin>>n;
	temp=1;
	power(n);
	ans=temp-f(n);
	if(ans<0){
		ans+=1000000007;
	}
	cout<<ans<<endl;
	return 0;
}