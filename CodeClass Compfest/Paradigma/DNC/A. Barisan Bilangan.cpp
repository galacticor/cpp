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

ll n,a,b,ans;

ll gcd(ll x,ll y){
	if(y==0) return x;
	else return gcd(y,x%y);
}

ll lcm(ll x,ll y){
	return (x/gcd(x,y) * y);
}

ll sum;
bool cek(ll x){
	sum=x/a + x/b - x/lcm(a,b);
	if(sum>=n) return true;
	else return false;
}

ll lo,hi,mid;
void binser(){
	lo=1;hi=9e18;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(cek(mid)){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>a>>b;
	binser();
	cout<<ans<<endl;
	return 0;
}