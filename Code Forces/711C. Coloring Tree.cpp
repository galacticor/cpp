#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

ll n,m,k,a[110],col[110],mins[110],p[110][110],mem[110][110][110],ans;

ll f(int x,int y,int z){
		
		if(x==0){
			if(y==0){
				return 0;
			}
			else return 9e18;
		}
		if(a[x]!=0){
			if(a[x]==z) return f(x-1,y,z);
			else return f(x-1,y-1,a[x]);
		}
		else if(mem[x][y][z]!=-1){
			return mem[x][y][z];
		}
		else{
			ll mins=9e18;
			for(int i=1;i<=m;i++){
				int temp=0;
				if(z!=i) temp=1;
				mins=min(mins,f(x-1,y-temp,i)+p[x][i]);
			}
			return mem[x][y][z]=mins;
		}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	memset(mem,-1,sizeof(mem));
	for(int i=1;i<=n;i++){
		mins[i]=2e9;
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
		}
	}
	ll ans=f(n,k,0);
	if(ans>1e18) ans=-1;
	cout<<ans<<endl;

	return 0;
}