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

inline void fastll(){
	while(char x = getchar_unlocked())
		if(x >= '0' && x <= '9') break;
	LL ret = (x-'0');
	while(char x = getchar_unlocked()){
		ret = (ret << 3) + (ret << 1) + (x-'0');
	}
}

vector<ll> v,v1;
ll maks=1e18;

void init(){
	for(ll i=2;i<=1e6;i++){
		for(ll j=i*i*i; j<=maks;j*=i){
			v.push_back(j);
			if(j>maks/i) break;
		}
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());

	for(int i=0;i<(int)v.size();i++){
		ll tmp=sqrt(v[i]);
		if(tmp*tmp!=v[i]) v1.push_back(v[i]);
	}

}

ll binser(ll x){
	ll lo=0,hi=(ll)v1.size()-1,mid;
	ll ret=-1;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(v1[mid]<=x){
			ret=mid;
			lo=mid+1;
		}
		else hi=mid-1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	int t;
	cin>>t;
	// for(int i=0;i<10;i++){
	// 	cout<<v1[i]<<" ";
	// }
	while(t--){
		ll a;
		cin>>a;
		ll tmp=binser(a)+1;
		//cout<<tmp<<" ";
		ll ans=a-(ll)sqrt(a)-tmp;
		cout<<ans<<endl;
	}

	return 0;
}