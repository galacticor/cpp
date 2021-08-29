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

int par[200005],cnt[200005],tempat[200005],n,m,t,p,q,kamar;
ll sum[200005];

int root(int a){
	if(par[a]==a)return a;
	else return par[a]=root(par[a]);
}

void merge(int a,int b){
		int x=root(tempat[a]);
		int y=root(tempat[b]);
		par[x]=y;
		sum[y]+=sum[x];
		cnt[y]+=cnt[x];
}

void broken(int a){
	int x=root(tempat[a]);
	sum[x]-=a;
	cnt[x]--;
	kamar++;
	tempat[a]=kamar;
	sum[tempat[a]]=a;
	cnt[tempat[a]]=1;
	par[tempat[a]]=tempat[a];
}

void init(){
	for(int i=1;i<=n;i++){
		par[i]=i;
		cnt[i]=1;
		sum[i]=i;
		tempat[i]=i;
	}
	kamar=n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>n>>m){
		init();
		for(int i=1;i<=m;i++){
			cin>>t;
			if(t==1){
				cin>>p>>q;
				if(root(tempat[p])!=root(tempat[q]))
					merge(p,q);
			}
			else if(t==2){
				cin>>p>>q;
				if(root(tempat[p])!=root(tempat[q])){
					broken(p);
					merge(p,q);
				}
			}
			else{
				cin>>p;
				cout<<cnt[root(tempat[p])]<<" "<<sum[root(tempat[p])]<<endl;
			}
		}
	}

	return 0;
}