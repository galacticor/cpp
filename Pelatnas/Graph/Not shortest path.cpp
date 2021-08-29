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

map<string,int> m;
vii v[205];
int dis[205][205],n,tc,k,mi,s,f;
bool vis[205][205];
queue<pii> q;

void init(){
	for(int i=0;i<=101;i++){
		v[i].clear();
		for(int j=0;j<=101;j++){
			dis[i][j]=1e9+5;
			vis[i][j]=false;
		}
	}
	m.clear();
}

void solve(){
	q.push({s,0});
	dis[s][0]=0;
	vis[s][0]=1;
	while(!q.empty()){
		int now=q.front().fi;
		int cnt=q.front().se;
		q.pop();
		//vis[now][cnt]=0;
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i].se;
			int cost=v[now][i].fi;
			if(dis[nxt][cnt+1]>dis[now][cnt]+cost){
				dis[nxt][cnt+1]=dis[now][cnt]+cost;
				if(!vis[nxt][cnt+1]){
					vis[nxt][cnt+1]=true;
					q.push({nxt,cnt+1});
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>tc;
	for(int t=1;t<=tc;t++){
		if(t>1) cout<<endl;
		cin>>n;
		init();
		for(int i=1;i<=n;i++){
			string in;
			cin>>in;
			m[in]=i;
		}
		cin>>mi;
		for(int i=1;i<=mi;i++){
			string in,out;
			int x;
			cin>>in>>out;
			cin>>x;
			v[m[in]].push_back({x,m[out]});
		}
		s=m["Calgary"];
		f=m["Fredericton"];
		solve();
		cout<<"Scenario #"<<t<<endl;
		// for(int i=0;i<=n;i++){
		// 	for(int j=0;j<=n;j++){
		// 		cout<<dis[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		cin>>k;
		int a;
		while(k--){
			cin>>a;
			int ans=1e9;
			a=min(n,a);
			for(int i=0;i<=a+1;i++){
				ans=min(ans,dis[f][i]);
			}
			if(ans<1e9){
				cout<<"Total cost of flight(s) is $";
				cout<<ans<<endl;
			}
			else{
				cout<<"No satisfactory flights"<<endl;
			}
		}
	}

	return 0;
}