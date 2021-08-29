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
const ld phi=acos(-1.0);
const ld eps=1e-9;

int dp[14][1001][1100][2][2],n,m;
char c[20][1005];

int rec(short int x,short int y,int mask,bool cek,bool cek1){
	// cout<<x<<" "<<y<<" "<<mask<<" "<<cek<<" "<<cek1<<endl;
	if(x>=n){
		if(cek==0 && cek1!=1) return 0;
		else return rec(0,y+1,mask,cek1,0);
	}
	if(y>=m){
		if(mask==(1<<n)-1) return 1;
		else return 0;
	}
	if(dp[x][y][mask][cek][cek1]!=-1) return dp[x][y][mask][cek][cek1];
	else{
		int ret=0;
		if(c[x][y]=='.'){
			ret+=rec(x+1,y,mask | (1<<x),cek,1);
			ret+=rec(x+1,y,mask,cek,cek1);
		}
		else{
			ret+=rec(x+1,y,mask,cek,cek1);
		}
		ret%=MOD;
		return dp[x][y][mask][cek][cek1]=ret;
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen ("masuk.txt","r",stdin);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	int ans=rec(0,0,0,1,0);
	while(ans<0) ans+=MOD;
	cout<<ans<<endl;

	return 0;
}