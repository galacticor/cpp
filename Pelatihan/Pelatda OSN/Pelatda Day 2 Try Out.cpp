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

struct name
{
	ll power;
	bool cek;
}sp[200005];

bool cmp(name x,name y){
	return x.power>y.power;
}

ll n,k,ans,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	k=0;
	for(int i=1;i<=n;i++){
		k++;
		cin>>sp[k].power;
		sp[k].cek=false;
		k++;
		cin>>sp[k].power;
		sp[k].cek=true;
	}
	sort(sp+1,sp+1+k,cmp);
	int i=1;
	ans=0;
	while(m>0){
		m-=sp[i].power;
		if(sp[i].cek){
			i++;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}