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

int dis[2005],n,m;
vi v[2005];

void bfs(){
	q.push(1);
	dis[1]=0;
	while(!q.empty()){
		int now=q.top();
		q.pop();
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i];
			if(!vis[nxt]){
				dis[nxt]=dis[now]+1;
				q.push(nxt);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char c;
			cin>>c;
			if(c=='#'){
				v[i].push_back(j+n);
				v[j+n].push_back(i);
			}
		}
	}
	dis[n]=-1;
	bfs();
	cout<<dis[n]<<endl;

	return 0;
}