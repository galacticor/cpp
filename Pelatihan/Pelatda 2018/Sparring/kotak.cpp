#include <bits/stdc++.h>
using namespace std;

long long memo[100010],n,t;

long long f(int x){
	if(x==1){
		return 1;
	}
	else if(x==2){
		return 3;
	}
	else if(x==3){
		return 6;
	}
	else if(memo[x]!=0){
		return memo[x]%1000000007;
	}
	else{
		memo[x]=(f(n-1))%1000000007+(2*f(n-2))%1000000007+(f(n-3))%1000000007;
	}
	return memo[x]%1000000007;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		cout<<f(n)<<endl;
	}

	return 0;
}