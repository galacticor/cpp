#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;

ll ans,n,m,k;

bool cek(ll x){
	ll tot=0;
	for(int i=1;i<=n;i++){
		tot+=min(m,x/i);
	}
	if(tot>=k) return true;
	else return false;
}

void binser(){
	ll lo=1,hi=m*n,mid;
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

	cin>>n>>m>>k;
	binser();
	cout<<ans<<endl;

	return 0;
}