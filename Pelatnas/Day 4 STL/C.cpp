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

ll n,l[100005],r[100005],ans;

bool cmp(ll x,ll y){
	return x>y;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	n++;
	l[n]=0;
	r[n]=0;
	sort(l+1,l+1+n);
	sort(r+1,r+1+n,cmp);
	for(int i=n;i>0;i--){
		if(l[i]>r[i]) ans+=2*(l[i]-r[i]);
		else break;
	}
	cout<<ans<<endl;

	return 0;
}