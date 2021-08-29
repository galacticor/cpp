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

queue<pii> q;
vi v;
int n,m,ax,by,dis[105][105],a[105][105];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[105][105];


void bfs(){
	while(!q.empty()){
		int x=q.front().fi;
		int y=q.front().se;
		q.pop();
		if(x==n || y==m || x==1 || y==1){
			v.push_back(dis[x][y]);
			return;
		}
		else{
			for(int i=0;i<4;i++){
				int xnxt=x+dx[i];
				int ynxt=y+dy[i];
				if(0<xnxt && 0<ynxt && xnxt<=n && ynxt<=m && !vis[xnxt][ynxt] && a[xnxt][ynxt]==0){
					vis[xnxt][ynxt]=true;
					q.push({xnxt,ynxt});
					dis[xnxt][ynxt]=dis[x][y]+1;
				}
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
			cin>>a[i][j];
		}
	}
	cin>>ax>>by;
	dis[ax][by]=1;
	q.push({ax,by});
	bfs();
	sort(v.begin(),v.end());
	int ans=1e9;
	for(int i=0;i<(int)v.size();i++){
		//cout<<v[i]<<endl;
		ans=min(ans,v[i]);
	}
	cout<<ans<<endl;
	return 0;
}