#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

std::map<string, int> m;
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		m[s]++;
		if(m[s]==1) cout<<"OK"<<endl;
		else cout<<s<<m[s]-1<<endl;
	}

	return 0;
}