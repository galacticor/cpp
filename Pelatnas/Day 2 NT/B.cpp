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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,x;
	cin>>t;
	while(t--){
		cin>>x;
		if(x%5==0) cout<<"0.00"<<endl;
		if(x%5==1 || x%5==4) cout<<"0.40"<<endl;
		if(x%5==3 || x%5==2) cout<<"0.20"<<endl;
	}

	return 0;
}