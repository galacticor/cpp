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

int n;
priority_queue<int> pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		int t,x;
		cin>>t;
		if(t==1){
			cin>>x;
			pq.push(x);
		}
		if(t==2){
			cout<<pq.top()<<endl;
		}
		if(t==3){
			pq.pop();
		}
	}

	return 0;
}