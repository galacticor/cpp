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

ll n,a[505],ans,temp,dp[505][505];

ll rec(int x,int y){
	if(x>=temp || y>n) return 0;
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	else{
		int res=0;
		if(a[x]==a[y]){
			res+=(rec(x+1,y+1)+1+rec(x+1,y))%MOD;
		}
		else res+=(rec(x+1,y)+rec(x,y+1)-rec(x+1,y+1))%MOD;
		return dp[x][y]=res%MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				temp=j;
				ans+=rec(i,j)%MOD;
			}
		}
	}
	cout<<ans%MOD<<endl;
	return 0;
}