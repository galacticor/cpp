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

ll prefix[305][305],prefmin[305][305],ans,h,n,m,ansbw2,anska1,anska2,ansbw1;
int a[305][305];

ll val(int ki,int at,int ka,int bw){
	return prefix[ka][bw]-prefix[ki-1][bw]-prefix[ka][at-1]+prefix[ki-1][at-1];
}

ll cekmin(int ki,int at,int ka,int bw){
	return prefmin[ka][bw]-prefmin[ki-1][bw]-prefmin[ka][at-1]+prefmin[ki-1][at-1];
}

void binser2(ll x,ll y){
	ll ki=x,ka=min(n-3+x,n),mid1;
	ll at=y,bw=min(m-3+y,m),mid2;
	while(at<=bw){
		mid2=(at+bw)/2;
		if(cekmin(x,y,x,mid2)>=0){
			ansbw2=mid2;
			at=mid2+1;
		}
		else{
			bw=mid2-1;
		}
	}

	while(ki<=ka){
		mid1=(ki+ka)/2;
		if(cekmin(x,y,mid1,ansbw2)>=0){
			anska2=mid1;
			ki=mid1+1;
		}
		else{
			ka=mid1-1;
		}
	}
}

void binser1(ll x,ll y){
	ll ki=x,ka=min(n-3+x,n),mid1;
	ll at=y,bw=min(m-3+y,m),mid2;
	while(ki<=ka){
		mid1=(ki+ka)/2;
		if(cekmin(x,y,mid1,y)>=0){
			anska1=mid1;
			ki=mid1+1;
		}
		else{
			ka=mid1-1;
		}
	}
	while(at<=bw){
		mid2=(at+bw)/2;
		if(cekmin(x,y,anska1,mid2)>=0){
			ansbw1=mid2;
			at=mid2+1;
		}
		else{
			bw=mid2-1;
		}
	}
}

void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]>=0){
				binser1(i,j);
				binser2(i,j);
				cout<<i<<" "<<j<<endl;
				if(val(i,j,anska1,ansbw1)>=h) ans=min(ans,val(i,j,anska1,ansbw1));
				cout<<ans<<endl;
				if(val(i,j,anska2,ansbw2)>=h) ans=min(ans,val(i,j,anska2,ansbw2));
				cout<<ans<<endl;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	cin>>n>>m>>h;
	ans=1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+a[i][j];
			prefmin[i][j]=prefmin[i-1][j]+prefmin[i][j-1]-prefmin[i-1][j-1]+min(0,a[i][j]);
		}
	}
	solve();
	if(ans==1e18){
		ans=-1;
	}
	cout<<ans<<endl;

	return 0;
}