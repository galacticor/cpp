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

vi v1,v2;
ll ans,prefix1[100005],prefix2[100005],a[100005],b[100005],n,c;

ll gain1(int x){
	int jarak=a[x];
	return b[x]-jarak;
}

ll gain2(int x){
	int jarak=c-a[x];
	return b[x]-jarak;
}

struct name
{
	ll val,idx;
}pmax2[100005],pmax1[100005];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	prefix1[0]=0;
	prefix2[0]=0;
	for(int i=1;i<=n;i++){
		prefix1[i]=prefix1[i-1]+b[i];
	}
	prefix2[n+1]=0;
	pmax2[n+1].val=0;
	for(int i=n;i>=1;i--){
		prefix2[i]=prefix2[i+1]+b[i];
		if(prefix2[i]-(c-a[i])>pmax2[i+1].val){
			pmax2[i].val=prefix2[i]-(c-a[i]);
			pmax2[i].idx=a[i];
		}
		else{
			pmax2[i].val=pmax2[i+1].val;
			pmax2[i].idx=pmax2[i+1].idx;
		}
		//cout<<pmax2[i].val<<endl;
	}
	for(int i=1;i<=n;i++){
			//cout<<i<<" ";
			ans=max(ans,prefix1[i]-a[i]);
			//cout<<prefix1[i]-a[i]<<" ";
			ans=max(ans,pmax2[i].val);
			//cout<<pmax2[i].val<<" ";
			ans=max(ans,prefix1[i]+pmax2[i+1].val-min(c-pmax2[i+1].idx,a[i])-a[i]);
			//cout<<prefix1[i]+pmax2[i+1].val-min(c-pmax2[i+1].idx,a[i])-a[i]<<endl;
		
	}
	cout<<ans<<endl;

	return 0;
}