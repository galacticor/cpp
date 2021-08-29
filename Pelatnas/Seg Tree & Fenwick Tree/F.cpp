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

vector<pii> v[100005];
ll aplen[100005],dep[100005],dis[100005];
ll par[100005],ances,tot1,tot2,n,sp[100005][20],t,maxdepth;

void dfs(int parnow,int now,ll depth){
	maxdepth=max(maxdepth,depth);
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i].fi;
		ll cost=v[now][i].se;
		if(nxt!=parnow){
			par[nxt]=now;
			dis[nxt]=dis[now]+cost;
			dep[nxt]=depth+1;
			dfs(now,nxt,depth+1);
		}
	}
}

void build(){
	for(int i=1;i<=n;i++){
		sp[i][0]=par[i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			sp[i][j]=sp[sp[i][j-1]][j-1];
		}
	}
}

ll ret;
int naik(int x,int k){
	ret=x;
	if(k>dep[x]){
		return 1;
	}
	while(k>0){
		ret=sp[ret][aplen[k]];
		if(ret==1)break;
		k-=(1<<aplen[k]);
	}
	return ret;
}

inline void query(int x,int y){
	tot1=dep[x];
	tot2=dep[y];
	if(dep[x]>dep[y]){
		x=naik(x,dep[x]-dep[y]);
	}
	else{
		y=naik(y,dep[y]-dep[x]);
	}
	int k=17;
	if(x==y){
		ances=x;
	}
	else{
		for(int i=k-1;i>=0;i--){
			if(sp[x][i]!=sp[y][i]){
				x=sp[x][i];
				y=sp[y][i];
			}
		}
		ances=sp[x][0];
	}
	tot1-=dep[ances];
	tot2-=dep[ances];
}

void init(){
	ll cur=1,cnt=0;
	aplen[0]=0;
	for(int i=1;i<=100000;i++){
		if(cur*2<=i){
			cur*=2;
			cnt++;
		}
		aplen[i]=cnt;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	init();
	int a,b,c;
	while(t--){
		cin>>n;
		for(int i=1;i<n;i++){
			cin>>a>>b>>c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		par[1]=1;
		dis[1]=0;
		
		dfs(1,1,0);
		build();
		string s;
		while(cin>>s){
			if(s=="DONE")break;
			if(s=="DIST"){
				cin>>a>>b;
				query(a,b);
				cout<<dis[a]+dis[b]-2*dis[ances]<<endl;
			}
			else{
				cin>>a>>b>>c;
				c--;
				query(a,b);
				if(c<=tot1){
					cout<<naik(a,c)<<endl;
				}
				else{
					c-=tot1;
					//cout<<c<<endl;
					cout<<naik(b,tot2-c)<<endl;
				}
			}
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		maxdepth=0;
	}

	return 0;
}