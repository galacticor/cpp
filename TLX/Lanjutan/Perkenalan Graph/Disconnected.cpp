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
 
ll res;
int t,n,e,q,r,ans,a[200005],b[200005],dest[200005];
int sum,tot;
bool sp[50005];
ll vis[50005],day;
vi v[50005];
queue<int> qu;
 
void bfs(int x){
	qu.push(x);
	while(!qu.empty()){
		int now=qu.front(); qu.pop();
		if(sp[now]){
			sum++;
		}
		for(int i=0;i<(int)v[now].size();i++){
			int nxt=v[now][i];
			if(vis[nxt]!=day){
				vis[nxt]=day;
				qu.push(nxt);
			}
		}
	}
}

void init(){
	while(!qu.empty()){
		qu.pop();
	}
	for(int i=0;i<50005;i++){
		v[i].clear();
	}
	memset(dest,0,sizeof(dest));
	memset(sp,0,sizeof(sp));
	
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin>>t;
	while(t--){
		cin>>n>>e>>q>>r;
		init();
		for(int i=1;i<=e;i++){
			cin>>a[i]>>b[i];
		}
		for(int i=1;i<=q;i++){
			int x;
			cin>>x;
			sp[x]=true;
		}
		for(int i=1;i<=r;i++){
			int x;
			cin>>x;
			dest[x]=true;
		}
		for(int i=1;i<=e;i++){
			if(!dest[i]){
				v[a[i]].push_back(b[i]);
				v[b[i]].push_back(a[i]);
			}
		}
		day++;
		tot=q;
		ans=0;
		for(int i=1;i<=n;i++){
			if(sp[i] && vis[i]!=day){
				
				sum=0;
				vis[i]=day;
				bfs(i);
				tot-=sum;
				ans+=tot*sum;
			}
		}
		cout<<ans<<endl;
	}
 
	return 0;
}