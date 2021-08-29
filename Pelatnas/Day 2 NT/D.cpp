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

map <ll,bool> m;
ll n,a;

ll gcd(ll x,ll y){
	if(y==0)return x;
	else return gcd(y,x%y);
}

bool cek(int x){
	if(x==1) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

vector <ll> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		m[a]=1;
		if(v.empty() || v[v.size()-1]!=a)
			v.push_back(a);
	}
	ll fpb;
	for(int i=0;i<(int)v.size();i++){
		fpb=v[i];
		for(int j=i+1;j<(int)v.size();j++){
			fpb=gcd(fpb,v[j]);
			//cout<<fpb<<endl;
			m[fpb]=1;
			if(fpb==1){
				break;
			}
		}
	}
	ll ans=(int)m.size();
	//cout<<ans<<endl;
	cout<<ans<<endl;

	return 0;
}