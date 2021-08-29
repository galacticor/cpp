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

int n;

ll dnc(int x,int y){
	ll t,tmp;
	if(y==0) return 1;
	if(y%2==0)tmp=1;
	else tmp=x;
	t=dnc(x,y/2);
	return ((t*t)%MOD * tmp)%MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	ll ans=dnc(2,n)-1;
	// ans+=MOD;
	// ans%=MOD;
	cout<<ans<<endl;

	return 0;
}