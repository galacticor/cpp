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

vi v[502];
int dp[502][2][502],n,r,ans,child[502],sibling[502],a[502];

void dfs(int now,int par){
	int last_child=-1;
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i];
		if(nxt==par) continue;
		if(child[now]==0){
			child[now]=nxt;
		}
		if(last_child!=-1){
			sibling[last_child]=nxt;
		}
		dfs(nxt,now);
		last_child=nxt;
	}
}

int rec(int now,int par,int cnt){
	int &ret=dp[now][par][cnt];
	if(ret!=-1*1e9) return ret;
	int ki=child[now];
	int ka=sibling[now];
	if(!ka && !ki){
		if(cnt==1 && par==1) return ret=a[now];
		if(cnt==0 && par==1) return ret=0;
		if(cnt==0 && par==0) return ret=max(0,a[now]);
		return ret=-1*8e8;
	}
	if(!cnt){
		if(!ki){
			ret=max(ret,rec(ka,par,cnt));
			if(!par) ret=max(ret,rec(ka,par,cnt)+a[now]);
		}	
		if(!ka){
			ret=max(ret,rec(ki,0,cnt));
			if(!par) ret=max(ret,rec(ki,1,cnt)+a[now]);
		}
		if(ka && ki){
			ret=max(ret,rec(ki,0,cnt)+rec(ka,par,cnt));
			if(!par) ret=max(ret,rec(ki,1,cnt)+rec(ka,par,cnt)+a[now]);
		}
		return ret;
	}
	if(!ki){
		ret=max(ret,rec(ka,par,cnt));
		if(par){
			ret=max(ret,rec(ka,par,cnt-1)+a[now]);
		}
		else{
			ret=max(ret,rec(ka,par,cnt)+a[now]);
		}
	}	
	if(!ka){
		ret=max(ret,rec(ki,0,cnt));
		if(par){
			ret=max(ret,rec(ki,1,cnt-1)+a[now]);
		}
		else{
			ret=max(ret,rec(ki,1,cnt)+a[now]);
		}
	}
	if(ka && ki){
		for(int i=0;i<=cnt;i++){
			int cnt_ki=i,cnt_ka=cnt-i;
			ret=max(ret,rec(ki,0,cnt_ki)+rec(ka,par,cnt_ka));
			if(i<=cnt){
				if(par){
					ret=max(ret,rec(ki,1,cnt_ki)+rec(ka,par,cnt_ka-1)+a[now]);
				}
			}
			if(!par){
				ret=max(ret,rec(ki,1,cnt_ki)+rec(ka,par,cnt_ka)+a[now]);
			}
		}
	}
	return ret;
}

// void copy(int x){
// 	for(int i=0;i<=n;i++){
// 		tmp[i][0]=dp[x][i][0];
// 		tmp[i][1]=dp[x][i][1];
// 		tmp[i][2]=dp[x][i][2];
// 	}
// }

// void dfs(int now,int par){
// 	for(int i=0;i<=n;i++){
// 		dp[now][i][0]=-1*1e9;
// 		dp[now][i][1]=-1*1e9;
// 	}
// 	dp[now][1][1]=a[now];
// 	dp[now][0][1]=0;
// 	dp[now][0][0]=max(0,a[now]);
// 	for(int i=0;i<(int)v[now].size();i++){
// 		int nxt=v[now][i];
// 		if(par==nxt)continue;
// 		copy(now);
// 	}
// }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>r;
	for(int i=1;i<=n;i++){
		int x;
		cin>>a[i]>>x;
		v[x].push_back(i);
		v[i].push_back(x);
	}
	dfs(0,-1);
	for(int i=0;i<=n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<=n;k++){
				dp[i][j][k]=-1*1e9;
			}
		}
	}
	int tmp=-1,ans=-1;
	for(int i=n-1;i>=0;i--){
		tmp=rec(child[0],0,i);
		//cout<<i<<" "<<tmp<<endl;
		if(tmp>=r){
			ans=i;
			break;
		}
	}
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<2;j++){
	// 		for(int k=0;k<=n;k++){
	// 			cout<<i<<" "<<j<<" "<<k<<" ";
	// 			cout<<dp[i][j][k]<<endl;
	// 		}
	// 	}
	// }
	cout<<ans<<endl;
	return 0;
}