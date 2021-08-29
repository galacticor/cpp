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

//Makasih Amnu pernah ngasih soal ini buat latihan...........!!!!!

ll par[200005],parnew[200005],tot[200005],sum[200005],n,m,nxt,p;

int root(int a){
	if(par[a]==a) return a;
	else return par[a]=root(par[a]);
}

void merge(int a,int b){
	int x=root(parnew[a]);
	int y=root(parnew[b]);
	par[x]=y;
	sum[y]+=sum[x];
	tot[y]+=tot[x];
}

void lepas(int a){
	int x=root(parnew[a]);
	sum[x]-=a;
	tot[x]--;
	nxt++;
	parnew[a]=nxt;
	tot[parnew[a]]=1;
	sum[parnew[a]]=a;
	par[parnew[a]]=parnew[a];
}

void init(){
	for(int i=1;i<=n;i++){
		sum[i]=i;
		par[i]=i;
		parnew[i]=i;
		tot[i]=1;
	}
	nxt=n;
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		cin>>p;
		int x,y;
		if(p==1){
			cin>>x>>y;
			if(root(parnew[x])!=root(parnew[y]))
				merge(x,y);
		}
		else if(p==2){
			cin>>x>>y;
			if(root(parnew[x])!=root(parnew[y])){
				lepas(x);
				merge(x,y);
			}
		}
		else{
			cin>>x;
			cout<<tot[root(parnew[x])]<<" "<<sum[root(parnew[x])]<<endl;
		}
	}


	return 0;
}