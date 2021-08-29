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

ll vis[100005],day;
vi v[100005];
int n,m,c,w[100005],val[100005],maks,qr,maxi[100005],par[100005];
queue<int> q;

void bfs(int x){
	while(!q.empty()){
		q.pop();
	}
	q.push(x);
	maks=val[x];
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i];
			if(vis[nxt]!=day){
				vis[nxt]=day;
				q.push(nxt);
				maks=max(maks,val[nxt]);
			}
		}
	}
}

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
	string sub;

	cin>>sub;
	cin>>n>>m>>c;
	init();
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		if(w[x]==w[y]){
			merge(x,y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	day=1;
	for(int i=1;i<=n;i++){
		//day++;
		if(vis[i]!=day){
			day++;
			vis[i]=day;
			bfs(i);
			maxi[root(i)]=maks;
		}
	}

	cin>>qr;
	if(sub[3]=='3'){
		for(int i=1;i<=qr;i++){
			int qu,x,y;
			cin>>qu;
			//cout<<qu<<" ";
			if(qu==1){
				cin>>x;
				cout<<maxi[root(x)]<<endl;
			}
			if(qu==2){
				cin>>x>>y;
				val[x]=y;
			}
		}
	}
	else {
		for(int i=1;i<=qr;i++){
			int qu,x,y;
			cin>>qu;
			//cout<<qu<<" ";
			if(qu==1){
				cin>>x;
				day++;
				vis[x]=day;
				bfs(x);
				cout<<maks<<endl;
			}
			if(qu==2){
				cin>>x>>y;
				val[x]=y;
			}
		}
	}
	return 0;
}