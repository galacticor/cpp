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
const ll MOD=1000000007;

ll n,k,tc,der[100005],fak[100005],invfak[100005],ans;

ll pow(ll x,ll y){
	if(y==0) return 1;
	if(y==1) return x;
	ll tmp,t;
	tmp=1;
	t=pow(x,y/2);
	if(y%2) tmp=x;
	return ((t*t)%MOD * tmp) %MOD;
}

void init(ll x){
	invfak[0]=1; fak[0]=1;
	der[0]=1;
	der[1]=0;
	der[2]=1;
	for(ll i=1;i<=x;i++){
		fak[i]=(fak[i-1]*i)%MOD;
		invfak[i]=pow(fak[i],MOD-2)%MOD;
	}
	for(ll i=3;i<=x;i++){
		der[i]=((i-1)*(der[i-1]+der[i-2]))%MOD;
	}
}

ll kombin(ll x,ll y){
	return ((fak[x]*invfak[y])%MOD * invfak[x-y])%MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>tc;
	init(100000);
	while(tc--){
		cin>>n>>k;
		ans=0;
		for(ll i=k;i<=n;i++){
			ans+=(((fak[n]*kombin(n,i))%MOD)*der[n-i])%MOD;
			ans%=MOD;
		}
		cout<<ans<<endl;
	}

	return 0;
}