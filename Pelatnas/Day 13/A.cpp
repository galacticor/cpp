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

ll n,r,dp[5002][5002][2],tmp[5002][2],harga[5002],disk[5002],p[5002];
vi v[5002];

void copy(int x){
	for(int i=0;i<=n;i++){
		tmp[i][0]=dp[x][i][0];
		tmp[i][1]=dp[x][i][1];
		tmp[i][2]=dp[x][i][2];
	}
}

void dfs(int now){

	for(int i=0;i<=n;i++){
		dp[now][i][0]=4e18;
		dp[now][i][1]=4e18;
		dp[now][i][2]=4e18;
	}

	dp[now][0][0]=0;
	dp[now][1][1]=harga[now]-disk[now];
	dp[now][1][0]=harga[now];

	for(int k=0;k<(int)v[now].size();k++){
		int nxt=v[now][k];
		dfs(nxt);
		copy(now);
		for(int i=0;i<=n;i++){
			dp[now][i][0]=4e18;
			dp[now][i][1]=4e18;
			dp[now][i][2]=4e18;
		}
		// status 1 = kalo dia ambil diskon, childnya bebas ambil atau enggak
		for(int i=0;i<=n;i++){
			for(int j=0;j<=i;j++){
				dp[now][i][1]=min(dp[now][i][1],tmp[j][1]+min(dp[nxt][i-j][0],dp[nxt][i-j][1]));
			}
		}
		// status 0 = kalo g ambil, childnya harus ga ambil
		for(int i=0;i<=n;i++){
			for(int j=0;j<=i;j++){
				dp[now][i][0]=min(dp[now][i][0],tmp[j][0]+dp[nxt][i-j][0]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=0;k<2;k++){
			for(int j=now+1;j<=n;j++){
				if(mins<harga[j] && !vis[now][i-1][k])
			}
			dp[now][i][k]=min(dp[now][i][k],dp[now][i-1][k]+mins);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen ("masuk.txt","r",stdin);

	cin>>n>>r;
	for(int i=1;i<=n;i++){
		cin>>harga[i];
		
	}
	for(int i=1;i<=n;i++){
		cin>>disk[i];
	}
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		p[i+1]=x;
		v[x].push_back(i+1);
	}
	dfs(1);
	int ans=-1;
	for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		for(int k=0;k<2;k++){
			if(dp[i][j][k]<=r){
				// cout<<dp[1][j][k]<<" "<<j<<endl;
				ans=max(ans,j);
			}
		}
	}
	}
	cout<<ans<<endl;

	return 0;
}