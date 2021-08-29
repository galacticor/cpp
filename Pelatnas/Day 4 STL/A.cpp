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

stack<ll> s;
ll n,a[100005];
ll maxarea,areatop,atas;

void solve(){
	maxarea=0,areatop=0;
	int i=0;
	while(i<n){
		if(s.empty() || a[i]>=a[s.top()]){
			s.push(i++);
		}
		else{
			atas=s.top();
			s.pop();
			if(s.empty()){
				areatop=a[atas]*i;
			}
			else{
				areatop=a[atas]*(i-s.top()-1);
			}

			maxarea=max(maxarea,areatop);
		}
	}
	while(!s.empty()){
		atas=s.top();
		s.pop();
		if(s.empty()){
			areatop=a[atas]*i;
		}
		else{
			areatop=a[atas]*(i-s.top()-1);
		}

		maxarea=max(maxarea,areatop);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("masuk.txt","r",stdin);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	solve();
	cout<<maxarea<<endl;
	return 0;
}