#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;
typedef vector<int> vi;

ll n;
vi v,ans;

void biner(ll x){
	while(x>0){
		ll temp=x%2;
		ans.push_back(temp);
		x/=2;
	}
}

ll temp,exps;
void init(ll x){
	exps=0;
	temp=1;
	while(temp-1<=x){
		temp*=2;
		exps++;
	}
	exps--;
	temp/=2;
}

void inserts(int x,int y){
	v.push_back(x);
	for(int i=(int)v.size()-1;i>=0;i--){
		swap(v[i],v[i-1]);
		if(v[i]==y+1) break;
	}
}

void solve(){
	init(n);
	for(ll i=1;i<=exps;i++){
		v.push_back(i);
	}
	// for(int i=0;i<v.size();i++){
	// 	cout<<v[i]<<" ";
	// }
	// cout<<endl;
	temp=n-temp+1;
	biner(temp);
	// for(int i=0;i<ans.size();i++){
	// 	cout<<ans[i]<<" ";
	// }
	// cout<<endl;
	// for(int i=0;i<v.size();i++){
	// 	cout<<v[i]<<" ";
	// }
	// cout<<endl;
	for(int i=0;i<ans.size();i++){
		if(ans[i]>0){
			inserts(exps+i+1,i);
		}
	}
	for(ll i=1;i<=exps;i++){
		v.push_back(i);
	}
	for(int i=(int)ans.size()-1;i>=0;i--){
		if(ans[i]>0){
			v.push_back(exps+i+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;

	solve();
    cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i];
		if(i<v.size()-1) cout<<" ";
	}
	cout<<endl;
	return 0;
}