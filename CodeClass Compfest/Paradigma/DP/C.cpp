#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
const int MOD=1000000007;

int n,a[5005],dp[5005],ans,sum;

void lis(){
	ans=-1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>a[j] && dp[j]+1>dp[i]){
				dp[i]=dp[j]+1;
			}
			ans=max(ans,dp[i]);
		}
	}
}

void solve(){
	memset(dp,0,sizeof(dp));
	lis();
	sum=0;
	for(int i=1;i<=n;i++){
		if(dp[i]==ans){
			sum++;
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
	solve();
	cout<<ans<<" "<<sum<<endl;

	return 0;
}