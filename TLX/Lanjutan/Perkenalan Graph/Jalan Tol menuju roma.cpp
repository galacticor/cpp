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

queue<pii> q;
vii v[125005];
int n,l,t,s,f,ans;
int dis[125005][5];

void bfs(){
	q.push({s,0});
	ans=2e9;
	dis[s][0]=0;
	dis[s][1]=0;
	while(!q.empty()){
		int tol=q.front().se;
		int now=q.front().fi;
		q.pop();
		if(now==f){
			ans=min(ans,dis[now][tol]);
			return;
		}
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i].fi;
			int tolnx=v[now][i].se;
			int jarak=dis[now][tol];
			if(tol==0){
				if(tolnx==1){
					if(dis[nxt][1]==0){
						q.push({nxt,1});
						dis[nxt][1]=jarak+1;
					}
				}
				else{
					if(dis[nxt][0]==0){
						q.push({nxt,0});
						dis[nxt][0]=jarak+1;
					}
				}
			}
			else{
				if(tolnx==0){
					if(dis[nxt][1]==0){
						q.push({nxt,1});
						dis[nxt][1]=jarak+1;
					}
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>l>>t>>s>>f;
	for(int i=1;i<=l;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back({y,0});
		v[y].push_back({x,0});
	}
	for(int i=1;i<=t;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back({y,1});
		v[y].push_back({x,1});
	}
	memset(dis,0,sizeof(dis));
	bfs();
	cout<<ans<<endl;
	return 0;
}