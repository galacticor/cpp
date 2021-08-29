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

bool gak=false;
ll a[100005],ans,dp[100005],s,n;
vi v[100005];
bool vis[100005];

void dfs(int now){
	ll maks=-1;
	if(gak) return;
	if((int)v[now].size()>1 || now==s){
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i];
			if(!vis[nxt]){
				vis[nxt]=true;
				dfs(nxt);
				maks=max(maks,dp[nxt]);
			}
		}
		if(now==s){
			if((ll)v[now].size()*maks+a[now]<=1e18){
				dp[now]=(ll)v[now].size()*maks+a[now];
				
			}
			else{
				ans=-1;
				gak=true;
				return;
			}	
		}
		else {
			if(((ll)v[now].size()-1)*maks+a[now]<=1e18){
				dp[now]=((ll)v[now].size()-1)*maks+a[now];
				
			}
			else{
				ans=-1;
				gak=true;
				return;
			}
		}
	}
	else{
		dp[now]=a[now];
	}
	//cout<<now<<" "<<dp[now]<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(vis,0,sizeof(vis));
	vis[s]=true;
	dfs(s);
	if(!gak)ans=dp[s];
	cout<<ans<<endl;

	return 0;
}