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

int gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y,x%y);
}

int solve(int x,int y,int z){
	int a=x, b=0, pindah;
	int ans=1;
	while(a!=z && b!=z){
		ans++;
		pindah=min(a,y-b);
		a-=pindah;
		b+=pindah;
		if(a==z || b==z){
			break;
		}

		if(a==0){
			ans++;
			a=x;
		}
		else if(b==y){
			b=0;
			ans++;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,a,b,c,ans;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if(c%gcd(a,b)!=0 || (c>a && c>b))ans=-1;
		else{
			ans=min(solve(a,b,c),solve(b,a,c));
		}
		cout<<ans<<endl;
	}

	return 0;
}