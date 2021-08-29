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

ll a[505][505],dp[505][505],ans,v,h,n;

ll rec(int x,int y,bool kanan,bool kiri){
	if(x==0 || y==0 || x>=v || y>=h) return 0;
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	else{
		
		return dp[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>v>>h>>n;
	for(int i=1;i<=n;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1;j<=x2;j++){
			for(int k=y1;k<=y2;k++){
				a[j][k]=1;
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=h;i++){
		ans=max(ans,rec(1,i,0,0));
	}
	cout<<ans<<endl;
	for(int i=1;i<=v;i++){
		for(int j=1;j<=h;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}