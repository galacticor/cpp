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

ll fact[1000005],invfact[1000005],ans1,ans2;

ll dnc(ll x,ll y){
	ll temp,t;
	if(y==0) return 1;
	if(y%2==1) temp=x;
	else temp=1;
	t=dnc(x,y/2)%MOD;
	return ((t*t)%MOD * temp)%MOD;
}

void init(ll x){
	fact[0]=1;
	invfact[0]=1;
	for(ll i=1;i<=x;i++){
		fact[i]=(fact[i-1]*i)%MOD;
		invfact[i]=dnc(fact[i],MOD-2)%MOD;
	}
}

ll combin(ll n, ll r){
	return (((fact[n]*invfact[n-r])%MOD)*invfact[r])%MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n,m,k;
	string s;
	
	cin>>s;
	cin>>n>>m>>k;
	
	init(m);
	ans1=dnc(2,(n-1)*m);
	ans2=combin(m,k);
	//cout<<ans1<<" "<<ans2<<endl;
	cout<<(ans1*ans2)%MOD<<endl;

	return 0;
}