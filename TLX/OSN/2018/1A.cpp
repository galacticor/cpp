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

ll res;

void solve(int x){
	if(x%2==0){
		if(p[i]+q[i]==ra[i] || r[i]+q[i]==pa[i] 
			|| p[i]==ra[i]+qa[i] || r[i]==pa[i]+qa[i]){
			res*=(fact[x/2]*fact[x/2])%MOD;
		}
	}
	else{
		if(p[i]+q[i])
	}
	if(p[i]+q[i]==ra[i]+qa[i] && r[i]==pa[i]){

	}else if(p[i]+q[i]==ra[i] && r[i]==pa[i]+qa[i]){

	}else if(p[i]==ra[i] && r[i]+q[i]==pa[i]+qa[i]){

	}else if(p[i]==ra[i]+qa[i] && r[i]+q[i]==pa[i]){

	}
}

void init(int x){
	fact[0]=1;
	for(int i=1;i<=x;i++){
		fact[i]=(fact[i-1]*i)%MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>sub;
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>h[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>h[a[i]]){
			p[a[i]]++;
		}
		else if(i==h[a[i]]){
			q[a[i]]++;
		}
		else if(i<h[a[i]]){
			r[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(i>h[b[i]]){
			pa[a[i]]++;
		}
		else if(i==h[b[i]]){
			qa[a[i]]++;
		}
		else if(i<h[b[i]]){
			ra[a[i]]++;
		}
	}
	init(n);
	for(int i=1;i<=k;i++){
		sz=p[i]+q[i]+r[i];
		sza=pa[i]+qa[i]+ra[i];
		if(sz==sza){
			solve(sz);
		}
	}

	return 0;
}