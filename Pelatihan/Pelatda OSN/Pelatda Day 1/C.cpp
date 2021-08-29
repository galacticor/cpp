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

map<ll, ll> m;
ll a,sum,temp,ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>a;
		sum+=a;
		temp=1;
		while(abs(temp)<=1e14){
			if(sum==temp) ans++;
			if(m[sum-temp].find()!=m.end()){
				ans+=m[sum-temp];
			}
			temp*=k;
			if(temp==1) break;
		}
		m[sum]++;
	}
	return 0;
}