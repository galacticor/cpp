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

ll n,a[1005][1005],par[1005],dis[1005];
bool vis[1005];
vi v[1005];

void dfs(int now){
	vis[now]=true;
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i];
		if(!vis[nxt]){
			dis[nxt]=dis[now]+a[now][nxt];
			dfs(nxt);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					if(a[i][j]!=0){
						cout<<"Tidak"<<endl;
						return 0;
					}
				}
				else{
					if(a[i][j]!=a[j][i] || a[i][j]==0){
						cout<<"Tidak"<<endl;
						return 0;
					}
				}
			}
	}
	for(int i=2;i<=n;i++){
		dis[i]=1e15;
		vis[i]=false;

	}
	dis[1]=0;
	par[1]=0;
	for(int i=1;i<=n;i++){
		ll mins=2e9;
		int idx;
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[j]<mins){
				mins=dis[j];
				idx=j;
				//cout<<j<<endl;
			}
		}
		vis[idx]=true;
		//cout<<idx<<endl;
		for(int j=1;j<=n;j++){
			if(idx==j) continue;
			if(a[idx][j]>0 && !vis[j] && a[idx][j]<dis[j]){
				par[j]=idx;
				dis[j]=a[idx][j];
			}
		}
	}

	for(int i=1;i<=n;i++){
		v[par[i]].push_back(i);
	}
	
	memset(vis,0,sizeof(vis));
	dfs(1);
	// for(int i=1;i<=n;i++){
	// 	cout<<dis[i]<<" "<<par[i]<<endl;
	// }
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<" "<<par[i]<<" "<<dis[i]<<endl;
	// }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(!(a[i][j]>=abs(dis[i]-dis[j]) 
				|| a[i][j]>=abs(dis[i]+dis[j]))){
				cout<<"Tidak"<<endl;
				return 0;
			}
		}
	}
	cout<<"Ya"<<endl;


	return 0;
}