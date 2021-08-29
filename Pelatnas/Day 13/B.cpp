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

int n,parent[100005];
ll dp[100005][4];
bool leaf[100005],vis[100005];
vi v[100005],v1[100005];

void dfs(int now,int par){
	vis[now]=true;
	if(par!=-1){
		v[par].push_back(now);
		leaf[par]=1;
		parent[now]=par;
	}
	for(int i=0;i<(int)v1[now].size();i++){
		int nxt=v1[now][i];
		if(!vis[nxt]){
			dfs(nxt,now);
		}
	}
}

void rec(int now){
	dp[now][0]=1;	// * 1
	dp[now][1]=0;	// 1 0
	dp[now][2]=3e8;	// 0 0
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i];
		rec(nxt);
		dp[now][0]+=min(dp[nxt][1],dp[nxt][0]);
		dp[now][1]+=dp[nxt][2];
	}
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i];
		dp[now][2]=min(dp[now][2],dp[now][1]-dp[nxt][2]+dp[nxt][0]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen ("masuk.txt","r",stdin);

	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	//memset(dp,-1,sizeof(dp));
	dfs(1,-1);
	rec(1);
	int ans=min(dp[1][0],dp[1][2]);
	cout<<ans<<endl;
	

	return 0;
}