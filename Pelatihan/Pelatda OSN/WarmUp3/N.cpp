#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

std::map<ll, ll> m;
ll n;
std::vector<ll> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>n){
		if(m[n]==0){
			v.push_back(n);
		}
		m[n]++;
	}
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" "<<m[v[i]]<<endl;
	}


	return 0;
}