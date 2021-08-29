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

bool cek;
vector<pair<int,pii>> v;
ll dis[2005];
int t,n,m;

void bellman(){
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			int cost=v[j].fi;
			int from=v[j].se.fi;
			int to=v[j].se.se;
			if(dis[to]>dis[from]+cost){
				dis[to]=dis[from]+cost;
			}
		}
	}
	cek=false;
	for(int j=0;j<m;j++){
		int cost=v[j].fi;
		int from=v[j].se.fi;
		int to=v[j].se.se;
		if(dis[to]>dis[from]+cost){
			cek=true;
			dis[to]=dis[from]+cost;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		cin>>n>>m;
		v.clear();
		for(int i=0;i<=2003;i++){
			dis[i]=2e18;
		}
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			v.push_back({z,{x,y}});
		}
		bellman();
		if(cek){
			cout<<"possible"<<endl;
		}
		else{
			cout<<"not possible"<<endl;
		}
	}

	return 0;
}