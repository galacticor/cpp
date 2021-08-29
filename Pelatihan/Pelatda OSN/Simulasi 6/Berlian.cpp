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

ll dp[1005],energi[1005],maksi[1005];
int x,n,w,b,cap[105],cost[105];
int s;

ll solve(int idx){
	if(idx>n) return 0;
	if(dp[idx]!=-1){
		return dp[idx];
	}
	else{
		ll res=0;
		for(int i=0;i<=cap[idx];i++){
			if(energi[idx]-i*cost[idx]<0){
				break;
			}
			maksi[idx+1]=maksi[idx]+i*b;
			energi[idx+1]=min(maksi[idx+1],energi[idx]-i*cost[idx]+x);
			res=max(res,solve(idx+1)+i);
		}
		return dp[idx];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>s;
	cin>>n>>w>>b>>x;
	for(int i=1;i<=n;i++){
		cin>>cap[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cost[i];
	}
	memset(dp,-1,sizeof(dp));
	ll ans=solve(1);
	cout<<ans<<endl;
	return 0;
}