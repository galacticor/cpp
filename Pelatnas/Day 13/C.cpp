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
const ll MOD=100000007;
const ld phi=acos(-1.0);
const ld eps=1e-9;

ll n,r,k,par[405],child[405],sibling[405],dp[405][2][405];
bool vis[405];
vector<ll> v[405];

void dfs(ll now,ll par){
	ll last_child=-1;
	for(int i=0;i<(int)v[now].size();i++){
		ll nxt=v[now][i];
		if(nxt==par) continue;
		if(child[now]==0){
			child[now]=nxt;
		}
		if(last_child!=-1){
			sibling[last_child]=nxt;
		}
		dfs(nxt,now);
		last_child=nxt;
	}
}

ll rec(ll now,int par,ll cnt){
	
	if(!cnt) return 1;
	ll &ret=dp[now][par][cnt];
	if(child[now]==0 && sibling[now]==0){
		if(cnt==1 && !par)return 1;
		return 0;
	}
	if(ret!=-1) return ret;
	ret=0;
		ll anak=child[now];
		ll sodara=sibling[now];
		if(sodara==0){
			ret+=rec(anak,0,cnt); 
			if(!par){
				ret+=rec(anak,1,cnt-1);
			}
		}
		if(anak==0){
			ret+=rec(sodara,par,cnt);
			if(!par){
				ret+=rec(sodara,1,cnt-1);
			}
		}
		if(sodara!=0 && anak!=0){
			for(ll i=0;i<=cnt;i++){
				ret+=rec(anak,0,i)*rec(sodara,par,cnt-i);
				if(!par && i!=k){
					ret+=rec(anak,1,i)*rec(sodara,1,cnt-i-1);
				}
				ret%=MOD;
			}
		}
		ret%=MOD;
		return ret;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen ("masuk.txt","r",stdin);

	cin>>n>>r>>k;
	for(int i=1;i<=r;i++){
		ll x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	memset(dp,-1,sizeof(dp));
	ll ans=rec(1,1,k);
	while(ans<0) ans+=MOD;
	cout<<ans<<endl;

	return 0;
}