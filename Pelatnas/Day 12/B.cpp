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
const ld phi=acos(-1.0);
const ld eps=1e-9;

ll n,ans,a[100005],b[100005];
priority_queue<ll,vector<ll>,greater<ll>> pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen ("masuk.txt","r",stdin);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		ll x=b[i]-a[i];
		if(i==1){
			ans+=b[i];
			continue;
		}
		if(i==n){
			ans+=a[i];
			break;
		}
		ans+=a[i];
		if(i%2==0){
			pq.push(x);
		}
		else{
			if(!pq.empty() && x>pq.top()){
				ans+=pq.top();
				pq.pop();
				pq.push(x);
			}
			else{
				ans+=x;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}