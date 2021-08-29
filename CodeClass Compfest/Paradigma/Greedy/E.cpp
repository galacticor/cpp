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

priority_queue<int> pq;
int n,a,b,res,ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		pq.push(a);
	}
	while(pq.size()>1){
		a=pq.top(); pq.pop();
		b=pq.top(); pq.pop();
		res=a-b;
		if(res>0)pq.push(res);
	}
	if(!pq.empty()){
		ans=pq.top();
	}
	else{
		ans=0;
	}
	cout<<ans<<endl;

	return 0;
}