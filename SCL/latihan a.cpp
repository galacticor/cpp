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

	freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);

	int T, N,A,B,C,D;
	cin>>T;
	while(T--){
		cin>>N>>A>>B>>C>>D;
		int sum = A + B + C + D;
		if (N  >= 2*sum){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
	}


	return 0;
}