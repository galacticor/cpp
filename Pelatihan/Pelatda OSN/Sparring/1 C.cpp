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

ll dis[100005];
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<pll> v[100005];
vi aktif,lewat;
bool sp[100005];
string sub;
int n,m,k,lanjut;
ll ans;

// void bfs(){
// 	while(!q.empty()){
// 		int now=q.top(); q.pop();
// 		for(int i=0;i<v[now].size();i++){
// 			int nxt
// 		}
// 	}
// }

void dijk(int x){
	while(!pq.empty()){
		dis[pq.top().se]=2e18;
		pq.pop();
	}
	dis[x]=0;
	pq.push({0,x});
	while(!pq.empty()){
		pii now=pq.top();
		pq.pop();
		lewat.push_back(now.se);
		if(dis[now.se]<now.fi){
			continue;
		}
		if(sp[now.se]){
			sp[now.se]=false;
			aktif.push_back(now.se);
			for(int i=0;i<(int)aktif.size();i++){
				if(aktif[i]==now.se)continue;
				v[now.se].push_back({0,aktif[i]});
			}
			lanjut=now.se;
			break;
		}
		for(int i=0;i<(int)v[now.se].size();i++){
			pii nxt=v[now.se][i];
			if(dis[now.se]+nxt.fi<dis[nxt.se]){
				dis[nxt.se]=dis[now.se]+nxt.fi;
				pq.push({dis[nxt.se],nxt.se});
			}
		}
	}
}

void init(){
	for(int i=1;i<=n;i++){
		//if(dis[i]!=2e18)cout<<i<<" ";
		dis[i]=2e18;
	}
}

void bersih(){
	for(int i=0;i<(int)lewat.size();i++){
		//cout<<lewat[i]<<" ";
		dis[lewat[i]]=2e18;
	}
	lewat.clear();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>sub;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({z,y});
		v[y].push_back({z,x});
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		sp[x]=true;
	}
	init();
	lanjut=1;
	// if(sub[6]=='6'){

	// }
	// else{
		while((int)aktif.size()<k){
			//cout<<lanjut<<endl;
			bersih();
			dijk(lanjut);
			ans+=dis[lanjut];
			//cout<<ans<<endl;
			//init();
			//cout<<endl;
		}
		cout<<ans<<endl;

	return 0;
}