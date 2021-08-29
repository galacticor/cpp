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

ll n,hah[1000005],a[1000005],sz=0;
bool p;

void add(ll x,ll y){
	ll temp=sz;
	while(sz<temp+y){
		//cout<<sz<<endl;
		sz++;
		a[sz]=x;
	}
	cout<<sz<<endl;
}

void del(ll x){
	if(sz<=0){
		return;
	}
	cout<<a[sz]+hah[sz]<<endl;
	hah[sz-1]+=hah[sz];
	sz--;
	ll temp=sz+1;
	ll tuj=temp-x;
	if(tuj<=0) tuj=0;
	while(sz>tuj){
		a[sz]=0;
		hah[sz-1]+=hah[sz];
		hah[sz]=0;
		sz--;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	p=false;
	memset(hah,0,sizeof(hah));
	for(int i=1;i<=n;i++){
		string s;
		ll x,y;
		cin>>s;
		//cout<<i<<endl;
		if(s=="add"){
			cin>>x>>y;
			add(x,y);
		}
		if(s=="del"){
			cin>>x;
			del(x);
		}
		if(s=="adx"){
			cin>>x;
			hah[sz]+=x;
		}
		if(s=="dex"){
			cin>>x;
			hah[sz]-=x;
		}
	}

	return 0;
}