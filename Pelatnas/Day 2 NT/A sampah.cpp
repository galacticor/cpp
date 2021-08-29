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

ll n,m,dp[100005][3];

int rec(int idx,int udah){
	if(idx<-1) return 0;
	if(idx==-1) return 1;
	else{
		if(dp[idx][udah]!=-1)return dp[idx][udah];
		ll ret=(rec(idx-m-1,1)%MOD+rec(idx-1,0)%MOD)%MOD;
		if(udah) ret+=rec(idx-1,1)%MOD;
		return dp[idx][udah]=ret;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	cout<<rec(n,0)<<endl;

	return 0;
}