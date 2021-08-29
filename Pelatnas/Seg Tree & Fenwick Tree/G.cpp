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

vi v[100005];
int aplen[100005],dep[100005],anak[100005];
int par[100005],ances,tot1,tot2,n,m,sp[100005][20],ans;

inline void dfs(int parnow,int now,int depth){
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i];
		if(nxt!=parnow){
			par[nxt]=now;
			dep[nxt]=depth+1;
			dfs(now,nxt,depth+1);
			anak[now]+=anak[nxt]+1;
		}
	}
}

inline void build(){

	for(int i=1;i<=n;i++){
		sp[i][0]=par[i];
	}
	
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i<=n;i++){
			sp[i][j]=sp[sp[i][j-1]][j-1];
		}
	}
}

int ret;
int naik(int x,int k){
	ret=x;
	if(k>dep[x]){
		return 1;
	}
	while(k>0){
		ret=sp[ret][aplen[k]];
		k-=(1<<aplen[k]);
	}
	return ret;
}

inline void query(int x,int y){
	tot1=dep[x];
	tot2=dep[y];
	if(dep[x]>dep[y]){
		x=naik(x,dep[x]-dep[y]);
	}
	else{
		y=naik(y,dep[y]-dep[x]);
	}
	int k=17;
	while(k>=0 && x!=y){
		int tmpx,tmpy;
		tmpx=naik(x,1<<k);
		tmpy=naik(y,1<<k);
		if(tmpx!=tmpy){
			x=tmpx;
			y=tmpy;
		}
		k--;
	}
	if(x!=y)ances=naik(x,1);
	else ances=x;
	tot1-=dep[ances];
	tot2-=dep[ances];
}

inline void init(){
	ll cur=1,cnt=0;
	aplen[0]=0;
	for(int i=1;i<=n;i++){
		if(cur*2<=i){
			cur*=2;
			cnt++;
		}
		aplen[i]=cnt;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a,b,ab,totdis,xab,yab;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	par[1]=0;
	dep[1]=0;
	init();
	dfs(1,1,0);
	build();
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<" "<<anak[i]<<endl;
	// }
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		query(a,b);
		totdis=tot1+tot2;
		//cout<<a<<" "<<b<<" "<<totdis<<endl;
		if(totdis==0){
			ans=n;
		}
		else if(totdis%2){
			ans=0;
		}
		else{
			//cout<<a<<" "<<b<<endl;
			int k=totdis/2;
			if(k<tot1){
				ab=naik(a,k);
				xab=naik(a,k-1);
				//cout<<"1 "<<ab<<" "<<xab<<endl;
				ans=anak[ab]-anak[xab];
			}
			else if(k>tot1){
				k-=tot1;
				ab=naik(b,tot2-k);
				xab=naik(b,tot2-k-1);
				//cout<<"2 "<<ab<<" "<<xab<<endl;
				ans=anak[ab]-anak[xab];
			}
			else{
				ab=naik(a,k);
				xab=naik(a,k-1);
				k-=tot1;
				yab=naik(b,tot2-k-1);
				//cout<<"3 "<<ab<<" "<<xab<<" "<<yab<<endl;
				ans=n-anak[xab]-anak[yab]-2;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}