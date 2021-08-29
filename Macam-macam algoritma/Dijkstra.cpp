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
ll dis[20005];
std::vector<pll> v[20005];
int n,m,s,f,tc;

void dijk(int x){
	while(!pq.empty()){
		pq.pop();
	}
	dis[x]=0;
	pq.push({0,x});
	while(!pq.empty()){
		now=pq.top(); pq.pop();
		if(dis[now.se]<now.fi){
			continue;
		}
		if(now.se==f){
			break;
		}
		for(int i=0;i<(int)v[now.se].size();i++){
			nxt=v[now.se][i];
			if(dis[nxt.se]>dis[now.se]+nxt.fi){
				dis[nxt.se]=dis[now.se]+nxt.fi;
				pq.push({dis[nxt.se],nxt.se});
			}
		}
	}
}

void init(){
	for(int i=0;i<=n;i++){
		dis[i]=4e18;
	}
	for(int i=0;i<=n;i++){
		v[i].clear();
	}
	while(!pq.empty()){
		pq.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>tc;
	while(tc--){
		cin>>n>>m>>s>>f;
		init();
		for(int i=0;i<m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			v[x].push_back({z,y});
			v[y].push_back({z,x});
		}
		dijk(s);
		cout<<"Case #"<<tc<<": ";
		if(dis[f]==4e18){
			cout<<"unreachable"<<endl;
		}
		else{
			cout<<dis[f]<<endl;
		}
	}

	return 0;
}