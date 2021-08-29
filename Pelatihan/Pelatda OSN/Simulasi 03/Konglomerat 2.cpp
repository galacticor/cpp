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

vi v;
int ans,r,c,h,w,a[3005][3005];

void solve(){
	for(int i=1;i<=r-h+1;i++){
		for(int j=1;j<=c-w+1;j++){
			for(int k=i;k<=i+h-1;k++){
				for(int l=j;l<=j+w-1;l++){
					v.push_back(a[k][l]);
				}
			}
			sort(v.begin(),v.end());
			//cout<<i<<" "<<j<<" "<<v[(h*w +1)/2 -1]<<endl;
			ans=min(ans,v[(h*w +1)/2 -1]);
			v.clear();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>r>>c>>h>>w;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>a[i][j];
		}
	}
	ans=1e9;
	solve();
	cout<<ans<<endl;

	return 0;
}