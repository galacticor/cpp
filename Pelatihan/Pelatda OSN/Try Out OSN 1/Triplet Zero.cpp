#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

ll a[10010],b[10010],c[10010],sum,ans,n;
int x;

map<ll,ll> c;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		c[x]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ll x=0-a[i]-b[j];
			sum+=c[x];
		}
	}
	cout<<sum<<endl;


	return 0;
}