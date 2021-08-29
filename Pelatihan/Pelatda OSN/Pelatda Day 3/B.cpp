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

queue<pair<int,pii>> q;
bool cek,vis[105][105][105];
char c[105][105][105], temp;
int l,w,h,endx,endz,endy,startx,starty,startz,dis[105][105][105];

void bfs(){
	while(!q.empty()){
		int x=q.front().fi;
		int y=q.front().se.fi;
		int z=q.front().se.se;
		q.pop();
		if(c[x][y][z]=='E'){
			cek=true;
			break;
		}
		if(0<x && 0<y && 0<z && x<=h && y<=l && z<=w && !vis[x][y][z] && c[x][y][z]!='#'){
			cout<<x<<" "<<y<<" "<<z<<endl;
			vis[x][y][z]=true;
			if(c[x][y][z]=='-'){
				if(x+1<=h && c[x+1][y][z]=='-' && dis[x+1][y][z] == -1){
					q.push({x+1,{y,z}});
					dis[x+1][y][z]=dis[x][y][z]+1;
				}
				if(x-1>0 && c[x-1][y][z]=='-'  && dis[x-1][y][z] == -1){
					q.push({x-1,{y,z}});
					dis[x-1][y][z]=dis[x][y][z]+1;
				}
			}
			if(y+1<=l  && dis[x][y+1][z] == -1){
				q.push({x,{y+1,z}});
				dis[x][y+1][z]=dis[x][y][z]+1;
			}
			if(y-1>0 && dis[x][y-1][z] == -1){
				q.push({x,{y-1,z}});
				dis[x][y-1][z]=dis[x][y][z]+1;
			}
			if(z+1<=w && dis[x][y][z+1] == -1){
				q.push({x,{y,z+1}});
				dis[x][y][z+1]=dis[x][y][z]+1;
			}
			if(z-1>0 && dis[x][y][z-1] == -1){
				q.push({x,{y,z-1}});
				dis[x][y][z-1]=dis[x][y][z]+1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin>>l>>w>>h && w && h && l){
		while(!q.empty()) q.pop();
		cek=false;
		memset(vis,0,sizeof(vis));
		memset(dis,-1,sizeof(dis));
		memset(c,' ',sizeof(c));
		for(int i=1;i<=h;i++){
			for(int j=1;j<=l;j++){
				for(int k=1;k<=w;k++){
					cin>>c[i][j][k];
					if(c[i][j][k]=='S'){
						startx=i;
						starty=j;
						startz=k;
						dis[i][j][k] = 0;
					}
					if(c[i][j][k]=='E'){
						endx=i; endy=j; endz=k;
					}
				}
			}
		}

		q.push({startx,{starty,startz}});
		bfs();
		for(int i=1;i<=h;i++){
			for(int j=1;j<=l;j++){
				for(int k=1;k<=w;k++){
					cout<<dis[i][j][k]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		if(!cek) cout<<"-1"<<endl;
		else{
			if(dis[endx][endz][endz]<=0) cout<<"-1"<<endl;
			else cout<<dis[endx][endz][endz]<<endl;
		}
	}

	return 0;
}
