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

vii v;
int n,k,ans;

bool cek(int x){
	int l,r,lnow=-1,rnow,sum=0;
	int ki=0,ka=ki;
	for(int ki=0;ki<n-k+1;ki++){
		rnow=v[ki].fi;
		lnow=max(lnow,v[ki].se);
		if(rnow-lnow+1>=x){
			while(ka<n){
				if(ka-ki+1>=k) return true;
				ka++;
				l=v[ka].se; r=v[ka].fi;
				lnow=max(l,lnow);
				if(rnow-lnow+1<x) break;
			}
		}
	}
	return false;
}

void binser(){
	int lo=1,hi=1000000000,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		cout<<mid<<endl;
		if(cek(mid)){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		v.push_back({y,x});
	}
	sort(v.begin(),v.end());
	if(1000<n && n<=100000){
		cout<<v[n-k].fi-v[n-k].se+1<<endl;
	}
	else{
		binser();
		cout<<ans<<endl;
	}
	return 0;
}