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
const ld phi=acos(-1.0);
const ld eps=1e-9;

ll n,m,dp[18][(1<<15)+5],a[20][20];
vector<pair<ll,int>> v[18];

ll rec(int now,int mask){
	// cout<<now<<" "<<mask<<endl;
	if(mask == (1<<n)-1){
		return a[now][0];
	}
	if(dp[now][mask]!=-1) return dp[now][mask];
	ll &ret=dp[now][mask];
	ret=2e9;
	for(int i=0;i<n;i++){
		ll cost=a[now][i];
		// if(nxt==0)continue;
		if((mask & (1<<i))==0){
			ret=min(ret,rec(i,mask | (1<<i))+cost);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen ("masuk.txt","r",stdin);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			a[i][j]=2e9;
		}
	}
	for(int i=1;i<=m;i++){
		int x,y;
		ll z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	ll ans;
	memset(dp,-1,sizeof(dp));
	ans=rec(0,1);
	cout<<ans<<endl;
	return 0;
}