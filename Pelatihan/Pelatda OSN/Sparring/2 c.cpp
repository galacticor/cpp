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

ll dis[1005];
std::vector<ll> v;
ll n,k,w[1005],d[1005];
string sub;

ll jar(int x,int y){
	return w[x]*(d[x]+d[y]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>sub;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	if(sub[4]=='4'){
		sort(d+1,d+1+n);
		
	}
	for(int i=1;i<=n;i++){
		ll sum=-1;
		for(int j=1;j<=n;j++){
			if(i!=j){
				sum=max(sum,jar(j,i));
			}
		}
		v.push_back(sum);
	}
	sort(v.begin(),v.end());
	cout<<v[k-1]<<endl;

	return 0;
}