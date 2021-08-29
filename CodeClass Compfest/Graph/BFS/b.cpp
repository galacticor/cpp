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

priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> q;
int o,x,y,nx,ny,n,ans;
char a[1005][1005];
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
bool vis[1005][1005];

void bfs(){
	q.push({0,{1,1}});
		while(!q.empty()){
			o=q.top().fi;
			x=q.top().se.fi;
			y=q.top().se.se;
			q.pop();
			//vis[x][y]=true;
			//cout<<o<<endl;
			if(vis[x][y])continue;
			vis[x][y]=1;
			if(a[x][y]=='1'){
							o++;
						}
			if(x==n && y==n){
				//cout<<x<<" "<<y<<endl;
				ans=o;
				break;
			}
				for(int i=0;i<4;i++){
					nx=x+dx[i];
					ny=y+dy[i];
					if(0<nx && nx<=n && 0<ny && ny<=n && !vis[nx][ny]){
						
						q.push({o,{nx,ny}});
					}
				}
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	memset(vis,false,sizeof(vis));
	//ans=1e9;
	bfs();
	cout<<ans<<endl;

	return 0;
}