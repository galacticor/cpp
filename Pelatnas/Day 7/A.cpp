#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;
const int MOD=1000000007;

priority_queue<pll,vpl,greater<pll>> pq;
ll n,m,dis[100005],dis1[100005],q,res;
vpl v[100005],v1[100005];

void mundur(){
	while(!pq.empty()) pq.pop();
	pq.push({0,n-1});
	dis1[n-1]=0;
	while(!pq.empty()){
		ll now=pq.top().se;
		ll dist=pq.top().fi;
		pq.pop();
		if(dis1[now]<dist) continue;
		if(now==0){
			break;
		}
		for(int i=0;i<(int)v1[now].size();i++){
			ll nxt=v1[now][i].se;
			ll cost=v1[now][i].fi;
			if(dis1[nxt]>dis1[now]+cost){
				dis1[nxt]=dis1[now]+cost;
				pq.push({dis1[nxt],nxt});
			}
		}
	}
}

void maju(){
	pq.push({0,0});
	dis[0]=0;
	while(!pq.empty()){
		ll now=pq.top().se;
		ll dist=pq.top().fi;
		pq.pop();
		if(dis[now]<dist) continue;
		if(now==n-1){
			break;
		}
		for(int i=0;i<(int)v[now].size();i++){
			ll nxt=v[now][i].se;
			ll cost=v[now][i].fi;
			if(dis[nxt]>dis[now]+cost){
				dis[nxt]=dis[now]+cost;
				pq.push({dis[nxt],nxt});
			}
		}
	}
	res=dis[n-1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({z,y});
		v1[y].push_back({z,x});
	}
	for(int i=0;i<=n;i++){
		dis[i]=1e18;
		dis1[i]=dis[i];
	}
	maju();
	mundur();
	// for(int i=0;i<=n-1;i++){
	// 	cout<<dis[i]<<" "<<dis1[i]<<endl;
	// }
	for(int i=1;i<=q;i++){
		int x,y,z;
		cin>>x>>y>>z;
		ll tmp=dis[x]+dis1[y]+z;
		if(tmp<res) cout<<"Ya"<<endl;
		else cout<<"Tidak"<<endl;
	}

	return 0;
}