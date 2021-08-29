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

int par[200005],n,q,k,x,y,parlama[200005];

int root(int a){
	if(par[a]==a)return a;
	else return par[a]=root(par[a]);
}

void merge(int a,int b){
	int x=root(a);
	int y=root(b);
	parlama[a]=x;
	parlama[b]=y;
	if(x!=y){
		par[x]=y;
	}

}

void unmerge(int a,int b){
	par[a]=parlama[a];
	par[b]=parlama[b];
}

bool connect(int a,int b){
	return root(a)==root(b);
}

void init(){
	for(int i=1;i<=n*2;i++){
		par[i]=i;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n>>q;
	init();
	while(q--){
		cin>>k>>x>>y;
		if(k==1){
			
			if(connect(x,y+n) || connect(x+n,y)){
				cout<<"-1"<<endl;
			}
			else{
				merge(x,y);
				merge(n+x,n+y);
				cout<<"1"<<endl;
			}
		}
		else if(k==2){
			if(connect(x,y) || connect(x+n,y+n)){
				cout<<"-1"<<endl;
			}
			else {
				merge(x,y+n);
				merge(y,x+n);
				cout<<"1"<<endl;
			}
		}
		else if(k==3){
			if(connect(x,y) || connect(x+n,y+n)) cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}
		else if(k==4){
			if(connect(x+n,y) || connect(x,y+n)) cout<<"1"<<endl;
			else cout<<"0"<<endl;		}
	}


	return 0;
}