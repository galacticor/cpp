#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

std::vector<ll> v;
ll a[50][50],vis[50][50],k,anskiri,anskanan,n,m;
string s;

void back(ll x,ll y,ll tot){
	if(0<x && 0<y && x<=n && y<=m && !vis[x][y]){
		if(x==n && y==m){
			v.push_back(tot+a[x][y]);
			return;
		}
		vis[x][y]=true;

		back(x+1,y,tot+a[x][y]);
		
		back(x-1,y,tot+a[x][y]);
		
		back(x,y+1,tot+a[x][y]);
		
		back(x,y-1,tot+a[x][y]);
		
		vis[x][y]=false;

	}

}

void binserkanan(ll x){
	ll lo=0,hi=v.size()-1,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(v[mid]>x){
			anskanan=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

void binserkiri(ll x){
	ll lo=0,hi=v.size()-1,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(v[mid]<x){
			anskiri=mid;
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

	cin>>s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	back(1,1,0);
	sort(v.begin(),v.end());
	cin>>k;
	for(int i=1;i<=k;i++){
		ll aw,ak;
		cin>>aw>>ak;
		anskiri=-1;
		anskanan=v.size();
		binserkiri(aw);
		binserkanan(ak);
		cout<<anskanan-anskiri-1<<endl;
	}

	return 0;
}