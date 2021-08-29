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

struct name
{
	int s,f;	
}a[100005];

int n,ans,pre;

bool cmp(name x,name y){
	return x.f<y.f;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].f;
	}
	sort(a+1,a+n+1,cmp);
	pre=1;
	for(int i=1;i<=n;i++){
		if(a[i].s>=pre){
			ans++;
			pre=a[i].f;
		}
	}
	cout<<ans<<endl;

	return 0;
}