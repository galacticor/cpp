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

deque<int> dq;
stack<int> st;
int n;
bool p;

void add(int x,int y){
	if(!p){
		for(int i=1;i<=y;i++){
			dq.push_back(x);
		}
		cout<<dq.size()<<endl;	
	}
	else{
		for(int i=1;i<=y;i++){
			dq.push_front(x);
		}
		cout<<dq.size()<<endl;
	}
}

void del(int x){
	if(!p){
		for(int i=1;i<=x;i++){
			if(i==1) cout<<dq.front()<<endl;
			dq.pop_front();
		}
	}
	else{
		for(int i=1;i<=x;i++){
			if(i==1) cout<<dq.back()<<endl;
			dq.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	p=false;
	for(int i=1;i<=n;i++){
		string s;
		int x,y;
		cin>>s;
		if(s=="add"){
			cin>>x>>y;
			add(x,y);
		}
		if(s=="del"){
			cin>>x;
			del(x);
		}
		if(s=="rev"){
			if(!p){
				p=true;
			}
			else p=false;
		}
	}

	return 0;
}