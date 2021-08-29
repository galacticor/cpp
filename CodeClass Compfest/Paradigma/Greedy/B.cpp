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

ll n,ans;

struct name
{
	ll a,b;
}makan[100005];

bool cmp(name x,name y){
	return x.b>y.b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>makan[i].a;
	}
	for(int i=1;i<=n;i++){
		cin>>makan[i].b;
	}
	sort(makan+1,makan+n+1,cmp);
	ans=0;
	for(int i=0;i<n;i++){
		ans+=(makan[i+1].a-makan[i+1].b*i);
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}