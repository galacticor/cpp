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

//std::map<ll, value> map;
int n,k,val[205];
ll sum,a[1500];

void rec(int x,ll sum){
	//cout<<x<<" "<<sum<<endl;
	if(x>n){
		a[sum]++;
		a[sum]%=MOD;
		return;
	}
	rec(x+1,sum%1465);
	rec(x+1,(sum*val[x])%1465);
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string sub;
	cin>>sub;
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		cin>>val[i];

	}
	//cout<<val[3]<<endl;
	// if(sub[4]=='4'){

	// }
	//else{
		rec(1,val[0]);
		for(int i=0;i<k;i++){
			cout<<a[i]<<endl;
		}
	//}


	return 0;
}