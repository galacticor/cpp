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
	int c,v;
}car[200005];

int n, k, s, t, g[200005], ans=-1;

bool cek(int x){
	int anst=0;
	for(int i=1;i<=k+1;i++){
		int a=g[i]-g[i-1];
		if(car[x].v>=a){
			anst+=2*a;
			if(car[x].v>=2*a){
				anst-=a;
			}
			else{
				anst-=(car[x].v-a);
			}
		}
		else return false;
	}
	// int a=s-g[k];
	// if(car[x].v>=a){
	// 		anst+=2*a;
	// 		if(car[x].v>=2*a){
	// 			anst-=a;
	// 		}
	// 		else{
	// 			anst-=(car[x].v-a);
	// 		}
	// 	}
	// else return false;

	if(anst<=t){
		return true;
	}
	else return false;
}

void solve(){
	int lo=1, hi=n, mid;
	while(lo <= hi){
		mid=(lo+hi)/2;
		if(cek(mid)){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
}

bool cmp(name a, name b){
	return a.v<b.v;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k >> s >> t;
	for(int i=1; i<=n; i++){
		cin>>car[i].c>>car[i].v;
	}
	for(int i=1; i<=k; i++){
		cin>>g[i];
	}
	sort(car+1,car+n+1,cmp);
	sort(g+1,g+k+1);
	g[0] = 0;
	g[k+1] = s;
	solve();

	if(ans < 0){
		cout<<ans<<endl;
		return 0;
	}

	int mins = 2e9;

	for(int i = ans; i <= n; i++){
		mins = min(mins, car[i].c);
	}
	cout<<mins<<endl;
	return 0;
}