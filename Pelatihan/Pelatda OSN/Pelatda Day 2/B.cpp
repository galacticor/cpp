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

int ans,n,m,x,y,a,prefix[110];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		prefix[i]=prefix[i-1]+a;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		ans+=max(0,prefix[y]-prefix[x-1]);
	}
	cout<<ans<<endl;
	return 0;
}