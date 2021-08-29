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

priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;
vector<pll> v[1005];
ll dis[1005][5];
int n,m,st,fn,y,a[1005];

void dijk(){
	dis[st][1]=0;
	dis[st][0]=0;
	pq.push({0,{st,0}});
	while(!pq.empty()){
		int now=pq.top().se.fi;
		int tol=pq.top().se.se;
		int jar=pq.top().fi;
		pq.pop();
		//cout<<now<<endl;
		if(dis[now][tol]<jar){
			continue;
		}
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i].se;
			int jarnxt=v[now][i].fi;
			if(tol==0){
				if(dis[nxt][1]>dis[now][tol]+1){
					dis[nxt][1]=dis[now][tol]+1;
					pq.push({dis[nxt][1],{nxt,1}});
				}
				if(dis[nxt][0]>dis[now][tol]+jarnxt){
					dis[nxt][0]=dis[now][tol]+jarnxt;
					pq.push({dis[nxt][0],{nxt,0}});
				}
			}
			else{
				if(dis[nxt][tol]>dis[now][tol]+jarnxt){
					dis[nxt][tol]=dis[now][tol]+jarnxt;
					pq.push({dis[nxt][tol],{nxt,tol}});
				}
			}
		}
	}
}

void init(){
	for(int i=1;i<=n;i++){
		dis[i][1]=2e18;
		dis[i][0]=2e18;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;

	cin>>s;
	cin>>n>>m>>st>>fn>>y;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({z,y});

	}
	init();
	dijk();
	// for(int i=1;i<=n;i++){
	// 	cout<<dis[i][0]<<" "<<dis[i][1]<<" "<<i<<endl;
	// }
	cout<<min(dis[fn][1],dis[fn][0])<<endl;
	return 0;
}