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

queue<int>q;
int n,m,a[202],dis[202][202],ans=2e9;
vi v[202];
bool vis[202];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=1e8;
		}
	}
	for(int i=1;i<=m;i++){
		int x,y,tmp;
		cin>>x>>y;
		if(a[x]==a[y]) tmp=0;
		else tmp=1;
		dis[x][y]=tmp;
		dis[y][x]=tmp;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int maks=0;
		for(int j=1;j<=n;j++){
			maks=max(maks,dis[i][j]);
		}
		ans=min(ans,maks);
	}
	cout<<ans<<endl;
	return 0;
}