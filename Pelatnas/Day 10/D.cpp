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
const ld eps=1e-9;

int a[1000005],n,x=1,ans[1000005];

void rec(int left,int right){
	int l=left,r=right,m=(l+r)/2;
  	//cout<<l<<" "<<r<<endl;
  	if(l==r) return;
    swap(a[m],a[l]);
	rec(l+1,r);
}

void solve(){
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	rec(1,n);
	for(int i=1;i<=n;i++){
		ans[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
		if(i<n) cout<<" ";
	}
	cout<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	// freopen("masuk.txt","r",stdin);

	cin>>n;
	solve();
	// if(n==7){
	// 	cout<<"7 6 5 1 4 3 2"<<endl;
	// 	return 0;
	// }
	// if(n==8){
	// 	cout<<"5 3 8 1 2 4 6 7"<<endl;
	// 	return 0;
	// }
	// if(n%2){
	// 	for(int i=1;i<(n+1)/2;i++){
	// 		cout<<i*2<<" ";
	// 	}
	// 	int tmp=n;
	// 	for(int i=(n+1)/2;i<=n;i++){
	// 		cout<<tmp;
	// 		tmp-=2;
	// 		if(i<n)cout<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// else{
	// 	for(int i=1;i<=(n+1)/2;i++){
	// 		cout<<i*2<<" ";
	// 	}
	// 	int tmp=1;
	// 	for(int i=(n+1)/2+1;i<=n;i++){
	// 		cout<<tmp;
	// 		tmp+=2;
	// 		if(i<n)cout<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"6 3 1 2 4 5"<<endl;
	

	return 0;
}