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

ll n,m,k,dis[5005],dis1[5005];
ld cnt[5005];
ll lewat[5005],lewat1[5005];
ll vis[5005],day,vis1[5005];
vi v[5005];
queue<int> q;

void bfs(int x){
	while(!q.empty()) q.pop();
	q.push(x);
	dis[x]=0;
	vis[x]=day;
	lewat[x]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i];
			//lewat[nxt]+=lewat[now];
			if(vis[nxt]!=day){
				//lewat[nxt]+=lewat[now];
				vis[nxt]=day;
				dis[nxt]=dis[now]+1;
				q.push(nxt);
			}
			if(vis[nxt]==day && dis[nxt]==dis[now]+1)lewat[nxt]+=lewat[now];
		}
	}
}

void bfs1(int x){
	while(!q.empty()) q.pop();
	q.push(x);
	dis1[x]=0;
	vis1[x]=day;
	lewat1[x]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i];
			//lewat1[nxt]+=lewat1[now];
			if(vis1[nxt]!=day){
				//lewat1[nxt]+=lewat1[now];
				vis1[nxt]=day;
				dis1[nxt]=dis1[now]+1;
				q.push(nxt);
			}
			if(vis1[nxt]==day && dis1[nxt]==dis1[now]+1)lewat1[nxt]+=lewat1[now];
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		day++;
		memset(lewat,0,sizeof(lewat));
		memset(lewat1,0,sizeof(lewat1));
		bfs(x);
		bfs1(y);
		//cout<<lewat[y]<<" "<<lewat1[x]<<endl;
		//cout<<dis[y]<<" "<<dis1[x]<<endl<<endl;
		for(int j=0;j<n;j++){
			if(dis[j]+dis1[j]==dis[y]){
				//cout<<dis[j]+dis1[j]<<" "<<dis[y]<<endl;
				cnt[j]+=((1.0*lewat1[j]*lewat[j])/(1.0*lewat[y]));
			}
		}
	}
	ld maks=0;
	int ans=0;
	for(int i=0;i<n;i++){
		//printf("%.4Lf%c", cnt[i], (i==n-1 ? '\n' : ' ') );
		//cout<<cnt[i]<<" ";
		if(maks<=cnt[i]){
			maks=cnt[i];
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}