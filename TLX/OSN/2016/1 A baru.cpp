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

std::vector<ll> v;
ll n,m,k,p,q,anskanan,anskiri,ans,a[50][50];
string s;
bool vis[50][50];

void binserkiri(ll x){
	ll lo=0,hi=v.size()-1,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(v[mid]>=x){
			anskiri=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

void binserkanan(ll x){
	ll lo=0,hi=v.size()-1,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(v[mid]<=x){
			anskanan=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

void solve(int x,int y,ll ans){
	if(x==n && y==m){
		ans+=a[x][y];
		v.push_back(ans);
		return;
	}
	if(0<x && 0<y && x<=n && y<=m && !vis[x][y]){
		vis[x][y]=true;
		solve(x+1,y,ans+a[x][y]);
		solve(x-1,y,ans+a[x][y]);
		solve(x,y+1,ans+a[x][y]);
		solve(x,y-1,ans+a[x][y]);
		vis[x][y]=false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	solve(1,1,0);
	sort(v.begin(),v.end());
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>p>>q;
		anskanan=-1;
		anskiri=-1;
		binserkiri(p);
		binserkanan(q);
		ans=anskanan - anskiri +1;
		if(anskiri==-1 || anskanan==-1) ans=0;
		cout<<ans<<endl;
	}

	return 0;
}