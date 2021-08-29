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

int dis[20][20],n,m;
std::vector<pair<int,pii>> v[20][20];
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
char c[20][20];
priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii> > > pq;
pii s,f;

void solve(){
	pq.push({0,{s.fi,s.se}});
	dis[s.fi][s.se]=0;
	while(!pq.empty()){
		int x=pq.top().se.fi;
		int y=pq.top().se.se;
		int dist=pq.top().fi;
		pq.pop();
		//cout<<x<<" "<<y<<" "<<dist<<endl;
		if(dis[x][y]<dist) continue;
		if(x==f.fi && y==f.se){
			break;
		}
		for(int i=0;i<(int)v[x][y].size();i++){
			int xn=v[x][y][i].se.fi;
			int yn=v[x][y][i].se.se;
			int cost=v[x][y][i].fi;
			if(dis[xn][yn]>dis[x][y]+cost){
				dis[xn][yn]=dis[x][y]+cost;
				pq.push({dis[xn][yn],{xn,yn}});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=2e9;
			cin>>c[i][j];
			if(c[i][j]=='O'){
				s.fi=i;
				s.se=j;
			}
			if(c[i][j]=='X'){
				f.fi=i;
				f.se=j;
			}
		}
	}
	// cout<<s.fi<<" "<<s.se<<endl;
	// cout<<f.fi<<" "<<f.se<<endl;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			if(c[i][j]!='#'){
				for(int k=0;k<4;k++){
					int tmpx=i+dx[k];
					int tmpy=j+dy[k];
					if(0<tmpx && tmpx<=n && 0<tmpy && tmpy<=m && c[tmpx][tmpy]!='#'){
						v[i][j].push_back({1,{tmpx,tmpy}});
					}
				}
				int tmp;
				for(int k=1;k<=max(n,m);k++){
					if(c[i+k][j]=='#' || i+k>n || c[i-k][j]=='#'
						|| i-k<=0 || c[i][j+k]=='#' || j+k>m || c[i][j-k]=='#'
						|| j-k<=0){
						tmp=k;
						break;
					}
				}
				for(int k=i;k<=n;k++){
					if(c[k+1][j]=='#'){
						v[i][j].push_back({tmp,{k,j}});
						break;
					}
					if(k==n){
						v[i][j].push_back({tmp,{k,j}});
					}
				}
				for(int k=i;k>0;k--){
					if(c[k-1][j]=='#'){
						v[i][j].push_back({tmp,{k,j}});
						break;
					}
					if(k==1){
						v[i][j].push_back({tmp,{k,j}});
					}
				}
				for(int k=j;k<=m;k++){
					if(c[i][k+1]=='#'){
						v[i][j].push_back({tmp,{i,k}});
						break;
					}
					if(k==m){
						v[i][j].push_back({tmp,{i,k}});
					}
				}
				for(int k=j;k>0;k--){
					if(c[i][k-1]=='#'){
						v[i][j].push_back({tmp,{i,k}});
						break;
					}
					if(k==1){
						v[i][j].push_back({tmp,{i,k}});
					}
				}
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		for(int k=0;k<(int)v[i][j].size();k++){
	// 			cout<<
	// 		}
	// 	}
	// }

	solve();
	int ans=dis[f.fi][f.se];
	if(ans>1e9) ans=-1;
	cout<<ans<<endl;

	return 0;
}