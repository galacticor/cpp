#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

ll dp1[160][15005],dp2[160][15005],ans,n,m,k,w,a[160],b[160],t;

ll f1(int x,int y){
	if(x==0){
		if(y==0){
			return 1;
		}
		else return 0;
	}
	if(y<0) return 0;
	if(dp1[x][y]!=-1){
		return dp1[x][y];
	}
	else{
		dp1[x][y]=(f1(x-1,y-a[x])+f1(x-1,y))%1000000007;
		return dp1[x][y];
	}
}
ll f2(int x,int y){
	if(x==0){
		if(y==0){
			return 1;
		}
		else return 0;
	}
	if(y<0) return 0;
	if(dp2[x][y]!=-1){
		return dp2[x][y];
	}
	else{
		dp2[x][y]=(f2(x-1,y-b[x])+f2(x-1,y))%(1000000007);
		return dp2[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>m>>k>>w;
		memset(dp1,-1,sizeof(dp1));
		memset(dp2,-1,sizeof(dp2));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		for(int i=0;i<=w;i++){
			if(abs(w-2*i)<=k){
				//cout<<i<<" "<<w-i<<endl;
				ans+=f1(n,i)%1000000007*f2(m,w-i)%1000000007;
				ans%=1000000007;
				//cout<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}