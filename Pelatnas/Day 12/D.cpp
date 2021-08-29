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
const ld pi=acos(-1.0);
const ld eps=1e-9;

int n,k,a[100005],ans;
bool vis[100005];
vi v[100005];

int dfs(int now){
	int ret=0;
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i];
		if(vis[nxt]) continue;
		vis[nxt]=1;
		int tmp=dfs(nxt)+1;
		if(tmp==k && now!=1){
			ans++;
		}
		else ret=max(ret,tmp);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen ("masuk.txt","r",stdin);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i == 1)continue;
		v[a[i]].push_back(i);
		v[i].push_back(a[i]);
	}
	if(a[1]!=1){
		ans++;
	}
	vis[1]=1;
	dfs(1);
	cout<<ans<<endl;

	return 0;
}