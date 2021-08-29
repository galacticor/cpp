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

ll r,c,k,ans,dp[1005];
vii batu;

ll dnc(ll x,ll y){
	ll tmp,t;
	if(y==0) return 1;
	if(y%2==1) tmp=x;
	else tmp=1;
	t=dnc(x,y/2)%MOD;
	return ((t*t)%MOD * tmp)%MOD;
}

ll fac[200005],invfac[200005];
void fact(ll x){
	fac[0]=1;
	invfac[0]=1;
	for(ll i=1;i<=x;i++){
		fac[i]=(fac[i-1]*i)%MOD;
		invfac[i]=dnc(fac[i],MOD-2)%MOD;
	}
}

ll kombin(ll x,ll y){
	//cout<<x<<" "<<y<<endl;
	if(x<0 || y<0) return 0;
	else return (((fac[x]*invfac[x-y])%MOD) * invfac[y])%MOD;
}

ll t1,t2,t3,t4;
ll f(int x){
	t1=batu[x].fi;
	t2=batu[x].se;
	return kombin(t1+t2-2,t1-1)%MOD;
}

ll g(int x,int y){
	t1=batu[x].fi;
	t2=batu[x].se;
	t3=batu[y].fi;
	t4=batu[y].se;
	return kombin(t3-t1+t4-t2,t3-t1)%MOD;
}

void solve(){
	fact(r+c);
	//ans=kombin(r+c-2,r-1);
	for(int i=0;i<=k;i++){
		dp[i]=f(i);
	}
	cout<<dp[k]<<endl;
	//cout<<g(0,1)<<endl;
	for(int i=0;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			dp[j]=(dp[j]-(dp[i]*g(i,j))%MOD)%MOD;
		}
	}
	//cout<<ans<<endl;
	// for(int i=0;i<k;i++){
	// 	ans-=dp[i];
	// 	while(ans<0)ans+=MOD;
	// }
	ans=dp[k];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>r>>c>>k;
	ll x,y;
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		batu.push_back({x,y});
	}
	batu.push_back({r,c});
	sort(batu.begin(),batu.end());
	//cout<<batu[k].fi<<batu[k].se<<endl;
	solve();
	cout<<ans<<endl;
	
	//cout<<dnc(2,6)<<endl;
	return 0;
}
