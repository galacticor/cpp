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

int dp[503][503],a[503],n;

int rec(int l,int r){
	if(l>r) return 0;
	if(dp[l][r]>0){
		return dp[l][r];
	}
	else{
		int res=2e9;
		res=min(res,min(rec(l+1,r)+1,rec(l,r-1)+1));
		for(int i=l+2;i<=r;i++){
			if(a[l]==a[i]){
				res=min(res,rec(l+1,i-1)+rec(i+1,r));
			}
		}
		if(a[l]==a[l+1]){
			res=min(res,rec(l+2,r)+1);
		}
		return dp[l][r]=res;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cout<<rec(1,n)<<endl;
	return 0;
}