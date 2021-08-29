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

priority_queue<pll,vector<pll>,greater<pll>> pq;
ll dis[5005],n,e,s,f;
std::vector<pll> v[5005];

void dijk(){
	while(!pq.empty()){
		pii now=pq.top();
		pq.pop();
		if(dis[now.se]<now.fi){
			continue;
		}
		//vis[now.se]=true;
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
		dis[i]=2e9;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>e>>s>>f;
	for(int i=1;i<=e;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({z,y});
		v[y].push_back({z,x});
	}
	init();
	dis[s]=0;
	pq.push({0,s});
	dijk();
	cout<<dis[f]<<endl;
	return 0;
}