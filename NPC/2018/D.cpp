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

int n,a,b,c,ans,x,y;

void solve(int a,int b){
	if(b==0){
		x=1;
		y=0;
		return;
	}
	solve(b,a%b);
	int xn=y;
	int yn=x-(a/b)*y;
	x=xn;
	y=yn;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int t=1;t<=n;t++){
		cin>>a>>b>>c;
		solve(a,b);

		
		ans=x+y;
		cout<<"Kasus#"<<t<<": "<<ans<<endl;
	}

	return 0;
}