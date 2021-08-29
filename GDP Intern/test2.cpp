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

map<string, int> m;
std::vector<string> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		m[s]++;
		if(m[s]==1){
			v.push_back(s);
		}
	}
	cout<<(int)v.size()<<endl;
	cout<<v[0];
	for(int i=1;i<(int)v.size();i++){
		cout<<" "<<v[i];
	}
	cout<<endl;

	return 0;
}