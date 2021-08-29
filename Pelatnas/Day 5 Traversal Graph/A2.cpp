#include <bits/stdc++.h>
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
const int MOD=1000000007;

struct name{
	int x, y;
	name(){}
	name(int _x, int _y){
		x = _x;
		y = _y;
	}
}jalan[300005];;
 
vi starts,akhir,beneran,v,adj[300005],rev[300005];
int n,m,a,b,ans[300005];
bool vis[300005];

void dfstimur(int now){
	for(int i = 0; i < adj[now].size(); i ++){
		int next = adj[now][i];
		if(vis[next])continue;
		vis[next] = 1;
		dfstimur(next);
	}
}
 
void dfsbarat(int now){
	for(int i = 0; i < rev[now].size(); i ++){
		int next=rev[now][i];
		if(vis[next])continue;
		vis[next]=1;
		dfsbarat(next);
	}
}
 
bool cmp(int a, int b){
	return jalan[a].y > jalan[b].y;
}
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>jalan[i].x>>jalan[i].y;
		if(jalan[i].x==0)starts.pb(i);
		if(jalan[i].x==a)akhir.pb(i);
	}
	for(int i=1;i<=m;i++){
		int st, en, type; cin>>st>>en>>type;
		if(type==1){
			adj[st].pb(en);
			rev[en].pb(st);
		}else{
			adj[st].pb(en);
			adj[en].pb(st);
			rev[st].pb(en);
			rev[en].pb(st);
		}
	}
	sort(starts.begin(), starts.end(), cmp);
	sort(akhir.begin(), akhir.end(), cmp);
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < starts.size(); i ++){
		if(vis[starts[i]])continue;
		vis[starts[i]] = 1;
		dfstimur(starts[i]);
	}
	for(int i = 0; i < akhir.size(); i ++){
		if(!vis[akhir[i]])continue;
		beneran.pb(akhir[i]);
	}
	memset(vis, 0, sizeof(vis));
	for(int i=0;i<beneran.size();i++){
		if(vis[beneran[i]])continue;
		dfsbarat(beneran[i]);
	}
	for(int i=0;i<starts.size();i++){
		if(vis[starts[i]])
			v.pb(starts[i]);
		else
			ans[starts[i]] = 0;
	}
	reverse(beneran.begin(), beneran.end());
	memset(vis, 0, sizeof(vis));
	sort(v.begin(), v.end(),cmp);
	int id=0;
	for(int i=v.size()-1;i>=0;i--){
		if(!vis[v[i]])
			dfstimur(v[i]);
		while(vis[beneran[id]] && id<beneran.size())
			id++;
		ans[v[i]]+=id;
	}
	memset(vis, 0, sizeof(vis));
	id = beneran.size()-1;
	for(int i=0;i< v.size(); i ++){
		if(!vis[v[i]])
			dfstimur(v[i]);
		while(vis[beneran[id]]&&id>=0)
			id--;
		ans[v[i]]-=id+1;
	}
	for(int i=0;i<starts.size();i++)
		cout<<ans[starts[i]]<<endl;
 
	return 0;
}