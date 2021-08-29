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


int t,a,b,f,ans;

int gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y,x%y);
}

void bfs(){
	queue<pair<ll,pii>> q;
	q.push({0,{0,0}});
	while(!q.empty()){
		int x=q.front().se.fi;
		int y=q.front().se.se;
		int dis=q.front().fi;
		q.pop();
		if(0<=x && x<=a && 0<=y && y<=b){
			if(x==f || y==f){
				ans=dis;
				return;
			}
			q.push({dis+1,{0,y}});
			q.push({dis+1,{x,0}});

			q.push({dis+1,{x,b}});
			q.push({dis+1,{a,y}});

			q.push({dis+1,{x+y,0}});
			q.push({dis+1,{a,y+x-a}});

			q.push({dis+1,{0,y+x}});
			q.push({dis+1,{y+x-b,b}});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		ans=-1;
		cin>>a>>b>>f;
		if(f%gcd(a,b)!=0 || (f>a && f>b))ans=-1;
		else bfs();
		cout<<ans<<endl;
	}

	return 0;
}