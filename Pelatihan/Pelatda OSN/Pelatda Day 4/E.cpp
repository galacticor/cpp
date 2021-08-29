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

int par[200005],n,q,x,y,que,parnxt[200005];

int root(int a){
	if(par[a]==a) return a;
	else return par[a] = root(par[a]);
}

bool connected(int a,int b){
	return root(a)==root(b);
}

void merge(int a,int b){
	if(!connected(a,b)) par[root(a)]=root(b);
}

void init(){
	for(int i=1;i<=n;i++){
		parnxt[i]=i+1;
		par[i]=i;
	}
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	scanf("%d%d",&n,&q);
	init();
	while(q--){
		scanf("%d%d%d",&que,&x,&y);
		if(que==1){
			merge(x,y);
		}
		if(que==2){
			for(int i=x+1;i<=y;){
				par[root(i-1)]=root(i);
				int temp=parnxt[i];
				parnxt[i]=parnxt[y];
				i=temp;
			}
		}
		if(que==3){
			if(!connected(x,y)) printf("NO\n" );
			else printf("YES\n" );
		}
	}

	return 0;
}