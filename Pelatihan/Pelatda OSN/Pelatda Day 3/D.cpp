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

queue<pii> q;
bool vis[505][505];
int r,c,k,a,b,dis[505][505],m,l;

void bfs(){
	q.push({1,1});
	dis[1][1]=0;
	while(!q.empty()){
		int x=q.front().fi;
		int y=q.front().se;
		q.pop();
		if(x==r && y==c){
			vis[x][y]=true;
			return;
		}
		if(0<x && 0<y && x<=r && y<=c && !vis[x][y]){
			vis[x][y]=true;
			q.push({x+1,y});
			dis[x+1][y]=dis[x][y]+1;
			q.push({x-1,y});
			dis[x-1][y]=dis[x][y]+1;
			q.push({x,y+1});
			dis[x][y+1]=dis[x][y]+1;
			q.push({x,y-1});
			dis[x][y-1]=dis[x][y]+1;
		}
	}
}

int main(){
	while(scanf("%d%d",&r,&c ) && r && c){
		while(!q.empty()) q.pop();
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			vis[x][y]=true;
		}
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d%d%d",&a,&b,&l);
			for(int i=a-l;i<=a+l;i++){
				for(int j=b-l;j<=b+l;j++){
					if(0<i && 0<j && i<=r && j<=c){
						int temp=(a-i)*(a-i)+(b-j)*(b-j);
						if(temp<=l*l) vis[i][j]=true;	
					}
				}
			}
		}
		bfs();
		if(!vis[r][c]) cout<<"Impossible."<<endl;
		else{
			if(dis[r][c]>0) cout<<dis[r][c]<<endl;
			else cout<<"Impossible."<<endl;
		}
	}

	return 0;
}