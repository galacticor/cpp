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

int n,m,q,a,b,par[100005],sum[100005];

int root(int x){
	if(x==par[x])return x;
	else return par[x]=root(par[x]);
}

bool connect(int x,int y){
	return root(x)==root(y);
}

ll temp,ax,bx;
void merge(int x,int y){
	ax=root(x);
	bx=root(y);
	if(!connect(x,y)){
		par[ax]=bx;
		temp=sum[ax]+sum[bx];
		sum[bx]+=sum[ax];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		par[i]=i;
		sum[i]=1;
	}

	for(int i=1;i<=m;i++){
		cin>>q>>a>>b;
		if(q==1){
			merge(a,b);
		}
		else{
			//cout<<sum[par[a]]<<" b "<<par[a]<<endl;
			//cout<<root(a)<<" "<<par[a]<<endl;
			//temp=root(a);
			cout<<sum[root(a)]<<endl;
		}
	}

	return 0;
}