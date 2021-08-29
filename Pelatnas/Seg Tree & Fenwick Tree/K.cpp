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

priority_queue<pll,vector<pll>,greater<pll>> pq;
int n,m,ans,cnt[105];
vector<pll> v[105];

void djikstra(int x,int y,int z){
	pll now,nxt;
	int tmp;
	while(!pq.empty()){
		pq.pop();
	}
	pq.push({0,x});
	while(!pq.empty()){
		now=pq.top();
		pq.pop();
		cnt[now.se]++;
		if(cnt[now.se]>z)continue;
		if(cnt[y]==z){
			ans=now.fi;
			break;
		}
		//cout<<now.se<<endl;
		for(int i=0;i<(int)v[now.se].size();i++){
			nxt=v[now.se][i];
			tmp=now.fi+nxt.fi;
			pq.push({tmp,nxt.se});
		}
	}
}

void init(){
	for(int i=0;i<105;i++){
		v[i].clear();
	}
	memset(cnt,0,sizeof(cnt));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>n>>m && n!=0 && m!=0){
		int a,b,k;
		cin>>a>>b>>k;
		init();
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			v[x].push_back({z,y});
		}
		ans=-1;
		djikstra(a,b,k);
		cout<<ans<<endl;
	}
	

	return 0;
}