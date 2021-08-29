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

int n,sd,sm,p[300010],k[300010],l[300010];
priority_queue<ll,vector<ll>,greater<ll>> pq;
ll ans=0;
string sub;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>sub;
	cin>>n>>sd>>sm;
	p[n]=sm;
	for(int i=1;i<n;i++){
		cin>>p[i]>>k[i]>>l[i];
	}
	for(int i=1;i<=n;i++){
		while(!pq.empty() && sd<p[i]){
			ans+=pq.top();
			pq.pop();
			sd++;
		}
		if(sd<p[i]){
			cout<<"-1"<<endl;
			return 0;
		}
		if(i<n){
			if(k[i]<l[i]){
				ans+=k[i];
				pq.push(l[i]-k[i]);
			}
			else{
				ans+=l[i];
				sd++;
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}