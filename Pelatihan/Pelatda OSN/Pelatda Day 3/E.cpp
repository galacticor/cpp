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

int r,c,b,s,dp[1005][1005],brd[1005];
char gr[1005][1005];
bool vis[1005][1005];

void flood(int x,int y){
	if(0<x && 0<y && x<=r && y<=c && !vis[x][y] && gr[x][y]=='#'){
		gr[x][y]='u';
		vis[x][y]=true;
		flood(x+1,y);
		flood(x-1,y);
		flood(x,y+1);
		flood(x,y-1);
	}
}

void flood1(int x,int y){
	if(0<x && 0<y && x<=r && y<=c && !vis[x][y] && gr[x][y]=='#'){
		gr[x][y]='d';
		vis[x][y]=true;
		flood1(x+1,y);
		flood1(x-1,y);
		flood1(x,y+1);
		flood1(x,y-1);
	}
}

int rec(int x,int y){
	if(y==0) return 0;
	if(x>c){
		if(y==0) return 0;
		else return 1e9;
	}
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	else{
		dp[x][y]=min(rec(x+s+1,y-1)+brd[x],rec(x+1,y));
		return dp[x][y];
	}
}

int main(){
	while(cin>>r>>c){
		memset(dp,-1,sizeof(dp));
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&b,&s);
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				cin>>gr[i][j];
			}
		}
		flood(1,1);
		flood1(r,c);
		for(int i=1;i<=c;i++){
			int at=0,bw=0;
			for(int j=1;j<=r;j++){
				if(gr[j][i]=='u'){
					at=j;
				}
				if(gr[j][i]=='d'){
					bw=j;
					break;
				}
			}
			brd[i]=bw-at-1;
		}
		cout<<rec(1,b)<<endl;
	}
	return 0;
}