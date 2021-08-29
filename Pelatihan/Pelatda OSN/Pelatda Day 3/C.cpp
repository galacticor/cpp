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

vii v[300005];
vi ans;
queue<int> q;
bool vis[300005],jlp[300005];
int n,k,d;

void bfs(){
	while(!q.empty()){
		int now=q.front(); q.pop();
		for(int i=0;i<v[now].size();i++){
			pii nxt=v[now][i];
			if(!vis[nxt.fi]){
				vis[nxt.fi]=true;
				q.push(nxt.fi);
				jlp[nxt.se]=true;
			}
		}
	}
}

int main(){
	
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=k;i++){
		int a;
		scanf("%d",&a);
		q.push(a);
		vis[a]=true;
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back({y,i});
		v[y].push_back({x,i});
	}
	bfs();
	for(int i=1;i<n;i++){
		if(!jlp[i]){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i];
		if(i<ans.size()-1) cout<<" ";

	}
	cout<<endl;
	return 0;
}