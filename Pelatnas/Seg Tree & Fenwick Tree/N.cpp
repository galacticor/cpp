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
const int MOD=1000000;						

ll dp[503][13][5050],n,m,ans;

int bit(int x,int ret){
	if(x==0)return ret;
	ret*=10;
	ret+=(x%2);
	return bit(x/2,ret);
}

ll solve(int x,int y,int mask){
	//cout<<x<<" "<<y<<" "<<bit(mask,0)<<" "<<mask<<endl;
	if(x>n){
		if(mask==((1<<m)-1)) return 1;
		else return 0;
	}
	if(y>m){
		if(mask && 1) return solve(x+1,2,(mask>>1));
		else return 0;
	}

/*	TIPE 1 : ##
			 #
		 2 : #
			 ##
		 3 :  #
			 ##
		 4 : ##
			  #
		 5 : ##
			 ## */

	if(dp[x][y][mask]!=-1)return dp[x][y][mask];
	ll ret=0;
	int a=mask & (1<<0);
	int b=mask & (1<<1);
	int c=mask & (1<<m);
	if(a){
		ret+=solve(x,y+1,(mask>>1));
	}
	if(!a && !b && !c){
		//Tipe 5
		int mask1=(mask>>1)+(1<<m)+(1<<(m-1))+(1<<0);
		ret+=solve(x,y+1,mask1);
	}
	if(!a && !b && !c){
		//Tipe 1
		int mask1=(mask>>1)+(1<<(m-1))+(1<<0);
		ret+=solve(x,y+1,mask1);
	}
	if(!a && !c){
		//Tipe 2
		int mask1=(mask>>1)+(1<<(m-1))+(1<<m);
		ret+=solve(x,y+1,mask1);	
	}
	if(!b && !c && a){
		//Tipe 3
		int mask1=(mask>>1)+(1<<(m-1))+(1<<0)+(1<<m);
		ret+=solve(x,y+1,mask1);	
	}
	if(!a&&!b){
		//Tipe 4
		int mask1=(mask>>1)+(1<<m)+(1<<0);
		ret+=solve(x,y+1,mask1);	
	}
	ret%=MOD;
	return dp[x][y][mask]=ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen ("masuk.txt","r",stdin);
	while(cin>>n>>m){
		if(n==0 || m==0)break;
		memset(dp,-1,sizeof(dp));		
		if(n<m)swap(n,m);
		ans=solve(2,2,0);
		while(ans<0){
			ans+=MOD;
		}
		cout<<ans<<endl;
	}

	return 0;
}