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

int n,m,k,day,vis[100005],dis[100005],nx,ans,res;
int now,nxt;
bool f[100005];

queue<int> q;
vi v[100005];
vi sodara;


void bfs(int x,int y){
	day++;
	while(!q.empty()){
		q.pop();
	}
	q.push(x);
	dis[x]=0;
	vis[x]=day;
	while(!q.empty()){
		now=q.front();
		//cout<<now<<endl;
		q.pop();
		if(now==y){
			nx=now;
			ans+=dis[now];
			break;
		}
		for(int i=0;i<(int)v[now].size();i++){
			nxt=v[now][i];
			if(vis[nxt]!=day){
				vis[nxt]=day;
				q.push(nxt);
				dis[nxt]=dis[now]+1;
			}
		}
	}
}

void solve(){
	sort(sodara.begin(), sodara.end());
	res=2e9;
	do{
		nx=1;
		ans=0;
		for(int i=0;i<(int)sodara.size();i++){
			bfs(nx,sodara[i]);
		}
		bfs(nx,1);
		res=min(ans,res);
	}while(next_permutation(sodara.begin(),sodara.end()));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		sodara.push_back(x);
	}
	solve();
	cout<<res<<endl;

	return 0;
}