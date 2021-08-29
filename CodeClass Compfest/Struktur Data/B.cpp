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

ll sum[100005],par[100005],n,m,maks,ans;

int root(ll x){
	if(par[x]==x) return x;
	return par[x]=root(par[x]);
}

bool connect(ll x,ll y){
	return root(x)==root(y);
}

void merge(ll x,ll y){
	if(!connect(x,y)) par[root(x)]=root(y);
}

void init(){
	for(int i=1;i<=n;i++){
		par[i]=i;
		sum[i]=0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	init();
	for(ll i=1;i<=m;i++){
		ll x,y;
		cin>>x>>y;
		if(!connect(x,y)){
			merge(x,y);
		}
		else{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;

	return 0;
}