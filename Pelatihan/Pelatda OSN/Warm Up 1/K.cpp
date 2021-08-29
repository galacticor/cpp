#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

ll n,k;
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			if(n/i==i){
				v.push_back(i);
			}
			else{
				v.push_back(n/i);
				v.push_back(i);
			}
		}
	}
	if(k>v.size()) cout<<"-1"<<endl;
	else {
		sort(v.begin(),v.end());
		cout<<v[k-1]<<endl;
	}
	return 0;
}