#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

int dp[50005],n,k,a[1000];

void f(){
	dp[0]=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(a[j]<=i){
				if(dp[i-a[j]]!=1e9 && dp[i-a[j]]+1<dp[i]){
					dp[i]=dp[i-a[j]]+1;
				}
			}
			
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>k;
	sort(a+1,a+n+1);
	for(int i=1;i<=k;i++){
		dp[i]=1e9;
	}
	f();
	cout<<dp[k]<<endl;
	return 0;
	
	return 0;
}