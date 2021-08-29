#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int memo[2005][2005],n,k,w[2005],h[2005],ans;

void solve(){
	int i=k,j=n;
	while(i>0 && j>0){
		if(memo[i][j]==ans){
			i--;
		}
		else{
			ans-=h[i+1];
			while(j>0 && memo[i][j]!=ans){
				j--;
			}
		}
	}
}

int f(int x,int y){
	if(y<0){
		return 1e9;
	}
	if(x==0){
		return 0;
	}
	if(memo[x][y]!=-1){
		return memo[x][y];
	}
	else{
		memo[x][y]=max(f(x-1,y),f(x-1,y-w[x])+h[x]);
		return memo[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i]>>h[i];
	}
	memset(memo,-1,sizeof(memo));
	ans=f(k,n);
	cout<<ans<<endl;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cout<<memo[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}