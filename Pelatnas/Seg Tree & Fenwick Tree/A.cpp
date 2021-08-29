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
const int MOD=5000000;

ll a[200005],ft[100005][55],ans,n,k;
int ax;

void update(int i,int j,ll val){
	while(i<=100000){
		ft[i][j]+=val;
		i+=(i & -i);	
	}
}

ll get(int i,int j){
	ll ret=0;
	while(i>0){
		ret+=ft[i][j];
		ret%=MOD;
		i-=(i & -i);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>ax;
		for(int j=1;j<=k;j++){
			ll temp;
			if(j==1) temp=1;
			else temp=get(ax,j-1);
			update(ax+1,j,temp);
			if(j==k){
				ans+=temp;
				ans%=MOD;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}