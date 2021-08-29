#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

int ans1,ans,dp[105][20005],n,k,a[105],t;

int f(int x,int y){
	if(x==0){
		if(y==0) return 0;
		else return 1e9;
	}
	if(y<0) return 1e9;
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	else{
		dp[x][y]=min(f(x-1,y),f(x-1,y-a[x])+1);
		return dp[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>k;
		cin>>n;
		ans=0; ans1=0;
		for(int i=1;i<=20000;i++){
			for(int j=1;j<=100;j++){
				dp[j][i]=-1;	
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			//dp[a[i]]=1;
		}
		for(int i=k;i<=20000;i++){
			ans1=f(n,i);
			if(ans1<1000){
				ans=i;
				break;
			}
		}
		cout<<ans<<" "<<ans1<<endl;
	}

	return 0;
}