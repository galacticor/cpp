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

int ans,prefixkol[1005][1005],prefixbar[1005][1005],a[1005][1005],n,m,j;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			prefixkol[i][j]=prefixkol[i][j-1]+a[i][j];
			prefixbar[i][j]=prefixbar[i-1][j]+a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==0){
				if(prefixbar[i-1][j]){
					ans++;
				}
				if(prefixkol[i][j-1]){
					ans++;
				}
				if(prefixbar[n][j]-prefixbar[i][j]){
					ans++;
				}
				if(prefixkol[i][m]-prefixkol[i][j]){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;


	return 0;
}