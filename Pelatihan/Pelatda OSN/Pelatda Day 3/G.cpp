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

vi kel[1005];
vi v[1005];
queue<int> q;
int dp[1005][1005],b[1005],a[1005],n,m,w,k;
bool vis[1005];
void bfs(){
	while(!q.empty()){
		int now=q.front(); q.pop();
		for(int i=0;i<v[now].size();i++){
			int nxt=v[now][i];
			if(!vis[nxt]){
				vis[nxt]=true;
				q.push(nxt);
				kel[k].push_back(nxt);
			}
		}
	}
}

int rec(int x,int y){
	//cout<<x<<" "<<y<<endl;
	if(y==0) return 0;
	if(y<0) return -1e9;
	if(x>k) {
		if(y>=0)return 0;
		else return -1e9;
	}
	if(y<0) return -1e9;
	if(dp[x][y]>0){
		return dp[x][y];
	}
	else{
		int res=-1;
		int berat=0,cantik=0;
		for(int i=0;i<kel[x].size();i++){
			int temp=kel[x][i];
			berat+=a[temp];
			cantik+=b[temp];
			//cout<<a[temp]<<" "<<b[temp]<<" ";
			if(a[temp]<=y) {
				res=max(res,rec(x+1,y-a[temp])+b[temp]);
			}
		}
		dp[x][y]=max(res,max(rec(x+1,y-berat)+cantik,rec(x+1,y)));
		return dp[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,0,sizeof(dp));
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	k=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			k++;
			kel[k].push_back(i);
			q.push(i);
			bfs();
		}
	}
	//cout<<k<<endl;
	// for(int i=1;i<=k;i++){
	//  	cout<<(int)kel[i].size()<<" ";
	//  	for(int j=0;j<kel[i].size();j++){
	//  		cout<<kel[i][j]
	//  	}
	// }
	cout<<rec(1,w)<<endl;
	
	return 0;
}