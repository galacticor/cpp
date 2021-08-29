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

ll fact[100005],invfact[100005];

ll dnc(ll x, ll y){
	ll temp,t;
	if(y==0) return 1;
	if(y%2==1) temp=x;
	else temp=1;
	t=dnc(x,y/2)%MOD;
	return (((t*t)%MOD)*temp)%MOD;
}

void init(int x){
	fact[0]=1;
	invfact[0]=1;
	for(ll i=1;i<=x;i++){
		fact[i]=(fact[i-1]*i)%MOD;
		invfact[i]=dnc(fact[i],MOD-2)%MOD;
	}
}

ll combin(ll n, ll r){
	return (((fact[n]*invfact[r])%MOD)*invfact[n-r])%MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init(100000);
	ll x,n,r;
	cin>>x;
	for(int i=1;i<=x;i++){
		cin>>n>>r;
		//cout<<fact[n]<<" "<<invfact[r]<<" "<<invfact[n-r]<<" ";
		cout<<n<<" "<<r<<" "<<combin(n,r)<<endl;
	}


	return 0;
}