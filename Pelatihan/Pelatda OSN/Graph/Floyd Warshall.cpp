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

int dis[515][515];
int x[515],ans[515],n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>dis[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int k=n;k>0;k--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[x[i]][x[j]]=min(dis[x[i]][x[j]],dis[x[i]][x[k]]+dis[x[k]][x[j]]);
			}
		}
		for(int i=k;i<=n;i++){
			for(int j=k;j<=n;j++){
				ans[k]+=dis[x[i]][x[j]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}