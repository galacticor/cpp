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

ll dis[505],fr[1005],to[1005],cost[1005],n,e,t;
bool cek;
vi v[505];

void bfs(int x){
	q.push(x);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now=)
		for(int i=0;i<v[now].size();i++){
			int nxt=v[now][i];
			if(!vis[nxt]){
				vis[nxt]=true;
				q.push(nxt);
			}
		}
	}
}

void ford(){
	bool p=false;
	dis[0]=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=e;j++){
			//cout<<fr[j]<<to[j]<<cost[j];
			if(dis[to[j]]>dis[fr[j]]+cost[j] && dis[fr[j]]!=2e18){
				dis[to[j]]=dis[fr[j]]+cost[j];
			}
			//cout<<dis[to[j]]<<endl;
		}
	}
	for(int j=1;j<=e;j++){
		//cout<<fr[j]<<to[j]<<cost[j];
		if(dis[to[j]]>dis[fr[j]]+cost[j] && dis[fr[j]]!=2e18){
			p=true;
			dis[to[j]]=dis[fr[j]]+cost[j];
		}
		//cout<<dis[to[j]]<<endl;
	}
	if(p) cek=false;
}

void init(){
	while(!q.empty()){
		q.pop();
	}
	for(int i=0;i<n;i++){
		dis[i]=(int)2e18;
	}
	cek=true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		cin>>n>>e;
		for(int i=1;i<=e;i++){
			cin>>fr[i]>>to[i]>>cost[i];
			v[fr[i]].push_back(to[i]);
		}
		dis[0]=0;
		ford();
		if(cek){
			if(dis[n-1]==(int)2e18){
				cout<<"Tidak ada jalan"<<endl;
			}
			else{
				cout<<dis[n-1]<<endl;
			}
		}
		else {
			bfs(0);
			cout<<"Pak Dengklek tidak mau pulang"<<endl;
		}
	}

	return 0;
}