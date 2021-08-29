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

ll n,a[1005][1005],sum,ans,k,day;
ll vis[1005][1005];
bool gus[1005][1005];

void flood(int x,int y){
	if(0<x && 0<y && x<=n && y<=n && vis[x][y]!=day && ((a[x][y]==-1 && gus[x][y]) || a[x][y]!=-1)){
		vis[x][y]=day;
		ll temp;
		if(gus[x][y]){
			temp=0;
		}
		else temp=a[x][y];
		sum+=temp;
		flood(x+1,y);
		flood(x-1,y);
		flood(x,y+1);
		flood(x,y-1);
		
	}
}

void cekmaks(int x,int y){
	if(0<x && 0<y && x<=n && y<=n && vis[x][y]!=day && a[i][j]!=-1){
		vis[x][y]=day;
		sum+=a[i][j];
		flood(x+1,y);
		flood(x-1,y);
		flood(x,y+1);
		flood(x,y-1);
		
	}
}

void gusur(int x,int y){
	for(int i=x;i<=x+k-1;i++){
		for(int j=y;j<=y+k-1;j++){
			gus[i][j]=true;
		}
	}
}

void ulang(int x,int y){
	for(int i=x;i<=x+k-1;i++){
		for(int j=y;j<=y+k-1;j++){
			gus[i][j]=false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	ans=-1;
	day=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!=-1 && vis[i][j]!=day){
				sum=0;
				day++;
				cekmaks(i,j);
				ans=max(ans,sum);
			}
		}
	}
	for(int i=1;i<=n-k+1;i++){
		for(int j=1;j<=n-k+1;j++){
			sum=0;
			day++; 
			gusur(i,j);
			flood(i,j);
			ulang(i,j);
			ans=max(sum,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}