#include <bits/stdc++.h>
#include <cmath>
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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	int t;
	double n;
	cin>>t;
	double pi = acos(-1.0);
	for (int i = 1; i <= t; i++){
		cin>>n;
		double ans = n*n/4;
		cout<<fixed
		cout<<"Case "<<t<<": "<<ans<<endl;
	}

	return 0;
}