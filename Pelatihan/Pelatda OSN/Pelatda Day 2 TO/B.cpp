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

int n,m,mins,maks,a[110][110],p,ans,b;
bool vis[110][110],cek;

void flood(int x,int y){
	if(x==n && y==m){
		cek=true;
		return;
	}
	if(0<x && 0<y && x<=n && y<=m && a[x][y]==p && !vis[x][y]){
		vis[x][y]=true;
		flood(x+1,y);
		flood(x-1,y);
		flood(x,y-1);
		flood(x,y+1);
	}
}

void back(int x,int y,int ma,int mi){
	if(ma-mi>=mins){
		return;
	}
	if(0<x && 0<y && x<=n && y<=m && !vis[x][y]){
		if(x==n && y==m){
			mins=min(mins,ma-mi);
		}
		vis[x][y]=true;
		back(x+1,y,max(ma,a[x][y]),min(mi,a[x][y]));
		back(x-1,y,max(ma,a[x][y]),min(mi,a[x][y]));
		back(x,y+1,max(ma,a[x][y]),min(mi,a[x][y]));
		back(x,y-1,max(ma,a[x][y]),min(mi,a[x][y]));
		vis[x][y]=false;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cek=false;
	cin>>n>>m;
	mins=1e9;
	if(n==1){
		mins=1e9;
		maks=-1;
		for(int i=1;i<=m;i++){
			cin>>b;
			mins=min(b,mins);
			maks=max(b,maks);
		}
		cout<<maks-mins<<endl;
		return 0;
	}
	bool haha=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(!(1<=a[i][j] && a[i][j]<=2)){
				haha=true;
			}
		}
	}
	if(!haha){
		p=a[1][1];
		flood(1,1);
		if(cek) cout<<"0"<<endl;
		else cout<<"1"<<endl;
	}
	else{
		back(1,1,-1,1000000000);
		cout<<mins<<endl;	
	}
	return 0;
}