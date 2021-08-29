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

ll sp[100005][50],x[100005],g[100005],d[100005],aplen[100005];
ll psumg[100005],psumd[100005],ans,maks,n,bplen[100005];

void build(){
	for(int i=1;i<=n;i++){
		sp[i][0]=x[i]-psumd[i-1];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			int now=i;
			int nxt=i+(1<<(j-1));
			sp[now][j]=max(sp[now][j-1],sp[nxt][j-1]);
		}
	}
}

ll ret,tmp,tmp1;
ll query(int l,int r){
	ret=-1;
	tmp=aplen[r-l+1];
	tmp1=bplen[r-l+1];
	ret=max(sp[l][tmp],sp[l-tmp1+1][tmp]);
	return ret;
}

ll binser(ll x){
	int lo=1,hi=n,mid;
	while(lo<hi){
		//cout<<"1"<<endl;
		mid=(lo+hi)/2;
		//cout<<lo<<" "<<mid<<endl;
		if(query(lo,mid)<x){
			lo=mid+1;
		}
		else{
			hi=mid;
		}
	}
	return lo;
}

void solve(){
	ll cur=1,cnt=0;
	for(int i=1;i<=100000;i++){
		if(cur*2<=i){
			cur*=2;
			cnt++;
		}
		aplen[i]=cnt;
		bplen[i]=cur;
	}
	build();
	maks=-1;
	ll kk;
	for(int i=n;i>0;i--){
		ans=-1;
		kk=binser(x[i]-psumd[i]);
		ans=psumg[i]-psumg[kk-1];
		maks=max(ans,maks);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	psumg[0]=0;
	psumd[0]=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>g[i]>>d[i];
		psumg[i]=psumg[i-1]+g[i];
		psumd[i]=psumd[i-1]+d[i];
	}
	solve();
	cout<<maks<<endl;
	//cout<<aplen[8]<<" "<<bplen[8]<<endl;

	return 0;
}