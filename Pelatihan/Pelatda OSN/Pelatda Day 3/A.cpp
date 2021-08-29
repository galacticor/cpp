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

char c[25][25],tempc;
int sum,n,m,x,y,maks;
bool vis[25][25];

void flood(int x,int y){
	if(y<0){
		y=m-1;
	}
	if(y==m){
		y=0;
	}
	if(0<=x && 0<=y && x<n && y<m && !vis[x][y] && c[x][y]==tempc){
		sum++;
		vis[x][y]=true;
		flood(x+1,y);
		flood(x-1,y);
		flood(x,y-1);
		flood(x,y+1);
	}
}

int main(){
	
	while(cin>>n>>m){
		memset(vis,false,sizeof(vis));
		//memset(c,' ',sizeof(c));
		maks=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>c[i][j];
			}
		}
		cin>>x>>y;
		tempc=c[x][y];
		flood(x,y);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(c[i][j]==tempc && !vis[i][j]){
					sum=0;
					flood(i,j);
					maks=max(maks,sum);
				}
			}
		}
		cout<<maks<<endl;
	}
	return 0;
}