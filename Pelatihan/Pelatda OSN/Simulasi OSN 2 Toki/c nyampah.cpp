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

priority_queue<int> pq;
ll n,m,a[305][305],res,dp[305][305],dp1[305][305];
bool vis[305][305];
std::vector<ll> v;

ll rec(int x,int y){
	if(x==0 || y==0){
		return 0;
	}
	if(dp[x][y]!=-2e9){
		return dp[x][y];
	}
	else{
		dp[x][y]=max(rec(x-1,y),rec(x,y-1))+a[x][y];
		return dp[x][y];
	}
}

ll rec1(int x,int y){
	if(x==1 && y==1){
		return a[x][y];
	}
	if(dp1[x][y]!=-2e9){
		return dp1[x][y];
	}
	else{
		dp1[x][y]=max(rec1(x-1,y),rec1(x,y-1))+a[x][y];
		return dp1[x][y];
	}
}

void back(int x,int y, ll ans){
	if(x==n && y==m){
		ans+=a[x][y];
		if(ans==res){
			//cout<<ans<<endl;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(vis[i][j]){
						//cout<<i<<" "<<j<<endl;
						a[i][j]=0;
					}
				}
			}
		}
		return;
	}
	if(0<x && 0<y && x<=n && y<=m && !vis[x][y]){
		vis[x][y]=true;
		back(x+1,y,ans+a[x][y]);
		//back(x-1,y,ans+a[x][y]);
		back(x,y+1,ans+a[x][y]);
		//back(x,y-1,ans+a[x][y]);
		vis[x][y]=false;
	}
}

bool cmp(ll a,ll b){
	return a>b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string sub;
	cin>>sub;

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=-2e9;
			dp1[i][j]=-2e9;
			cin>>a[i][j];
			if(i==1){
				dp[i][j]=dp[i][j-1]+a[i][j];
			}
			if(j==1){
				dp[i][j]=dp[i-1][j]+a[i][j];
			}
		}
	}
	res=rec(n,m);
	back(1,1,0);
	//cout<<a[3][3]<<endl;
	res+=rec1(n,m);
	cout<<res<<endl;
	return 0;
}