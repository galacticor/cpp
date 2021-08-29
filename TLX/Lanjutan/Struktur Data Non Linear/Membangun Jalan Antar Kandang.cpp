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

int n,q,par[100005],t,a,b;

int root(int x){
	if(par[x]==x) return x;
	else return par[x]=root(par[x]);
}

bool connect(int x,int y){
	return root(x)==root(y);
}

void merge(int x,int y){
	if(!connect(x,y)){
		par[root(x)]=root(y);
	}
}

void init(){
	for(int i=1;i<=n;i++){
		par[i]=i;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>q;
	init();
	for(int i=1;i<=q;i++){
		cin>>t>>a>>b;
		if(t==1){
			merge(a,b);
		}
		if(t==2){
			if(connect(a,b)) cout<<"Y"<<endl;
			else cout<<"T"<<endl;
		}
	}

	return 0;
}