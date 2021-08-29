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
const int MOD=1000000;
const ld phi=acos(-1.0);
const ld eps=1e-9;

int n,m,dp[505][12][2050];

int rec(int x,int y,int mask){
	// cout<<x<<" "<<y<<" "<<mask<<endl;
	if(y>m){
		if(mask & 1) return rec(x+1,2,(mask>>1));
		else return 0;
	}

	if(x>n){
		if(mask == (1<<m)-1) return 1;
		else return 0;
	}
	if(dp[x][y][mask]!=-1) return dp[x][y][mask];
	else{
		int ret=0;
		int a0=mask & (1<<0);
		int a1=mask & (1<<1);
		int am=mask & (1<<m);
		if(a0){
			//SKIP
			ret+=rec(x,y+1,mask>>1);
		}
		if(!a0 && !a1 && !am){
			//FULL
			int mask1=(mask>>1) | (1<<0) | (1<<m) | (1<<(m-1));
			ret+=rec(x,y+1,mask1);
		}
		if(!a0 && !am){
			int mask1=(mask>>1) | (1<<m) | (1<<(m-1));
			ret+=rec(x,y+1,mask1);	
		}
		if(!a1 && !am && a0){
			int mask1=(mask>>1) | (1<<0) | (1<<(m-1)) | (1<<m);
			ret+=rec(x,y+1,mask1);	
		}
		if(!a0 && !am && !a1){
			int mask1=(mask>>1) | (1<<0) | (1<<(m-1));
			ret+=rec(x,y+1,mask1);	
		}
		if(!a0 && !a1){
			int mask1=(mask>>1) | (1<<0) | (1<<m);
			ret+=rec(x,y+1,mask1);
		}
		ret%=MOD;
		return dp[x][y][mask]=ret;
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen ("masuk.txt","r",stdin);

	cin>>n>>m;
	if(n<m) swap(n,m);
	memset(dp,-1,sizeof(dp));
	int ans=0;
	ans=rec(2,2,0);
	while(ans<0) ans+=MOD;
	cout<<ans<<endl;

	return 0;
}