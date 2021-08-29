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

ll prefix[305][305],prefmin[305][305],ans,a,n,m,h;

ll val(int ki,int at,int ka,int bw){
	return prefix[ka][bw]-prefix[ki-1][bw]-prefix[ka][at-1]+prefix[ki-1][at-1];
}

ll cekmin(int ki,int at,int ka,int bw){
	return prefmin[ka][bw]-prefmin[ki-1][bw]-prefmin[ka][at-1]+prefmin[ki-1][at-1];
}


void solve(){
	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=m-2;j++){
			for(int k=1;k<=n-i+1;k++){
				for(int l=1;l<=m-j+1;l++){
					if(cekmin(k,l,k+i-1,l+j-1)<0){
						k=k+i-2;
					}
					if(val(k,l,k+i-1,l+j-1)>=h){
						ans=min(ans,val(k,l,k+i-1,l+j-1));
					}
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	cin>>n>>m>>h;
	ans=1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int a;
			cin>>a;
			prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a;
			prefmin[i][j]=prefmin[i-1][j]+prefmin[i][j-1]-prefmin[i-1][j-1]+min(0,a);
		}
	}
	solve();
	if(ans==1e18){
		ans=-1;
	}
	cout<<ans<<endl;

	return 0;
}