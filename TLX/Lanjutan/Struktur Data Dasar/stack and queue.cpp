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

int n,x;
string s;
deque<int> dq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s=="push_back"){
			cin>>x;
			dq.push_back(x);
		}
		if(s=="push_front"){
			cin>>x;
			dq.push_front(x);
		}
		if(s=="pop_back"){
			dq.pop_back();
		}
		if(s=="pop_front"){
			dq.pop_front();
		}
	}
	while(!dq.empty()){
		cout<<dq.front()<<endl;
		dq.pop_front();
	}

	return 0;
}