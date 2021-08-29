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

int n,m,x,y,nx,ny,ans;
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int dis[1005][1005];
bool vis[1005][1005];
char c[1005][1005];

queue <pii> q;

void bfs(){
	q.push({1,1});
	dis[1][1]=0;
	while(!q.empty()){
		x=q.front().fi;
		y=q.front().se;
		q.pop();
		if(x==n && y==m){
			ans=dis[x][y];
			break;
		}
		if(vis[x][y]){
			continue;
		}
		vis[x][y]=true;
		for(int i=0;i<4;i++){
			nx=x+dx[i];
			ny=y+dy[i];
			if(0<nx && nx<=n && 0<ny && ny<=m && !vis[nx][ny] && c[nx][ny]=='.'){		
				q.push({nx,ny});
				dis[nx][ny]=dis[x][y]+1;
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
			cin>>c[i][j];
		}
	}
	ans=-1;
	bfs();
	cout<<ans<<endl;

	return 0;
}