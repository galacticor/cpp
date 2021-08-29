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

vi v[100005],an[100005][19];
int dep[100005],tmp;
int par[100005],ances,n,m,q,sp[100005][19];

inline void dfs(int parnow,int now){
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i];
		if(nxt!=parnow){
			par[nxt]=now;
			dep[nxt]=dep[now]+1;
			dfs(now,nxt);
		}
	}
}

vi merge(vi a,vi b){
	vi ret;
	int i=0,j=0;
	while(i<a.size() && j<b.size() && ret.size()<11){
		if(a[i]<b[j]){
			ret.push_back(a[i]);
			i++;
		}
		else{
			ret.push_back(b[j]);
			j++;
		}
	}
	while(ret.size()<11 && i<a.size()){
		ret.push_back(a[i]);
		i++;
	}
	while(ret.size()<11 && j<b.size()){
		ret.push_back(b[j]);
		j++;
	}
	return ret;
}

vi get(int x,int k){
	vi ret;
	for(int i=0;i<17;i++){
		if((1<<i)&k){
			ret=merge(ret,an[x][i]);
			x=sp[x][i];
		}
	}
	return ret;
}

inline void build(){
	for(int i=1;i<=n;i++){
		sp[i][0]=par[i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			sp[i][j]=sp[sp[i][j-1]][j-1];
			an[i][j]=merge(an[i][j-1],an[sp[i][j-1]][j-1]);
		}
	}
}

int naik(int x,int k){
	int ret=x;
	for(int i=0;i<17;i++){
		if((1<<i)&k){
			ret=sp[ret][i];
		}
	}
	return ret;
}

int lca(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	x=naik(x,dep[x]-dep[y]);
	int k=17;
	if(x==y){
		return x;
	}
	else{
		for(int i=k-1;i>=0;i--){
			if(sp[x][i]!=sp[y][i]){
				x=sp[x][i];
				y=sp[y][i];
			}
		}
		return sp[x][0];
	}
}

inline void init(){
	par[1]=0;
	dep[1]=0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a,b,c;
	cin>>n>>m>>q;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=m;i++){
		cin>>a;
		an[a][0].push_back(i);
	}
	init();
	dfs(1,1);
	build();
	vi ans,ax,bx;
	while(q--){
		cin>>a>>b>>c;
		ances=lca(a,b);
		ax=get(a,dep[a]-dep[ances]);
		bx=get(b,dep[b]-dep[ances]+1);
		ans=merge(ax,bx);
		tmp=min(c,(int)ans.size());
		cout<<tmp;
		for(int i=0;i<tmp;i++){
			cout<<" "<<ans[i];
		}
		cout<<"\n";
	}

	return 0;
}