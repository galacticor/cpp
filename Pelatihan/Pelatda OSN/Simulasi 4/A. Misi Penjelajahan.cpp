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
	int l,r,lnow,rnow,sum=0;
	for(int i=0;i<n-k+1;i++){
		sum=1;
		lnow=v[i].se;
		rnow=v[i].fi;
		if(rnow-lnow+1<x) continue;
		for(int j=i+1;j<n;j++){
			r=v[j].fi; l=v[j].se;
			//cout<<lnow<<" "<<rnow<<" "<<l<<" "<<r;
			if(r<rnow){
				rnow=r;
				if(r-l+1>=x) sum++;
				else continue;
			}
			else if(rnow-l+1>=x){
				sum++;
			}
			else continue;
			lnow=l;
			//cout<<" "<<sum<<endl;
			if(sum>=k){
				return true;
			}
		}
	}
	return false;
}

void binser(){
	int lo=1,hi=1000000000,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		//cout<<mid<<endl;
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