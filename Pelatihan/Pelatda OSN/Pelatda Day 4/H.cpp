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

int n,m,dis[100005];
bool vis[100005],p[100005];

priority_queue<int> pq;
vi v[100005];

int now,nxt;
void solve(){
	while(!pq.empty()){
		now=pq.top(); pq.pop();
		for(int i=0;i<(int)v[now].size();i++){
			nxt=v[now][i];
			dis[nxt]=temp;
			temp--;

		}
	}
}

int main(){
	temp=n;
	memset(dis,-1,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[y].push_back(x);
		p[x]=true;
	}
	for(int i=1;i<=n;i++){
		if(!p[i]){
			pq.push(i);
		}
	}
	solve();
	for(int i=1;i<=n;i++){
		printf("%d", dis[i]);
		if(i<n) cout<<" ";
	}
	cout<<endl;
	return 0;
}