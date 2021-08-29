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

queue<int> q;
ll dis[1005],temp,ans;
int n,m,s,f,yy,a[1005];
bool vis[1005];
vi v[1005];

void bfs(){
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now==f){
			break;
		}
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i];
			if(!vis[nxt]){
				vis[nxt]=true;
				q.push(nxt);
				dis[nxt]=dis[now]+1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string sub;

	cin>>sub;
	cin>>n>>m>>s>>f>>yy;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		temp=z;
		v[x].push_back(y);
	}
	if(sub[4]='4'){
		bfs();
		//cout<<dis[f]<<endl;
		ans=((dis[f]+1)/2)*temp + dis[f]/2 ;
		cout<<ans<<endl;
	}

	return 0;
}