#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

long long n,t,memo[110],memo1[110];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memo[0]=1;
	memo[1]=1;
	memo[2]=3;
	memo[3]=5;
	memo1[0]=1;
	memo1[1]=1;
	memo1[2]=3;
	memo1[3]=1;
	for(int i=4;i<=30;i++){
		memo[i]=memo[i-1]+2*memo[i-2];
		memo1[i]=memo1[i-2]+2*memo1[i-4];
	}

	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		cout<<(memo[n] - memo1[n])/2 + memo1[n]<<endl;
	}

	return 0;
}