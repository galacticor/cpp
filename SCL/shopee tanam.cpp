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


ll memo[1005][1005], a[1005][1005], prefix[1005], suffix[1005];
bool vis[1005][1005];
int n, m;

ll dp(int x, int y){
	if(y == 1){
		return dp(x+1,y);
	}

	if(memo[x][y] != 0){
		return memo[x][y];
	}
	else{
		// y=1 --> kiri
		ll am;
		if (y == 1){
			

		}
		else{

		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for (int i = 0; i <= n; i++){
			prefix[i] = 0;
			suffix[i] = 0;
		}
		for (int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin>>a[i][j];
				memo[i][j] = 0;
				vis[i][j] = false;
			}
		}

		for (int i = 1; i <= n; i++){
			prefix[i] = a[i][1];
			suffix[i] = a[i][m];
			for(int j = 2; j <= m; j++){
				prefix[i] = max(prefix[i],prefix[i] + a[i][j]);
				suffix[i] = max(suffix[i],suffix[i] + a[i][m-j+1]);
			}
			prefix[i] = max(ll(0), prefix[i]);
			suffix[i] = max(ll(0), suffix[i]);
		}

		for (int i = 1; i <= n; i++){
			cout<<prefix[i]<< " "<<suffix[i]<<endl;
		}
		cout<<"Case"<<endl;

		// ans = dp(1,1);
	}


	return 0;
}
