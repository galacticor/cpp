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

ll vis[2005][2005],day;
char c[2005][2005];
int n,m,k,q,ansx,ansy;
string s;
struct name
{
	int ex,ye;
}nxt[2005][2005];
vii ikan;

int dy[4]={0,1,0,-1},dx[4]={1,0,-1,0};
queue<pair<int,pii>> que;
vector<pair<int,pii>> v;
void bfs(int xi,int yi){
	while(!que.empty()){
		que.pop();
	}
	que.push({0,{xi,yi}});
	v.clear();
	while(!que.empty()){
		int dis=que.front().fi;
		int x=que.front().se.fi;
		int y=que.front().se.se;
		que.pop();
		//cout<<x<<" p "<<y<<endl;
		if((int)v.size()>=2){
			
			if(v[0].fi<v[1].fi){
				nxt[xi][yi].ex=v[0].se.fi;
				nxt[xi][yi].ye=v[0].se.se;
			}
			else{
				nxt[xi][yi].ex=0;
				nxt[xi][yi].ye=0;	
			}
			return;
		}
		if(c[x][y]=='X' && x!=xi && y!=yi){
			v.push_back({dis,{x,y}});
		}
		else{
			for(int i=0;i<4;i++){
				int xnxt=x+dx[i];
				int ynxt=x+dy[i];
				if(0<xnxt && 0<ynxt && xnxt<=n && ynxt<=m && vis[xnxt][ynxt]!=day){
					vis[xnxt][ynxt]=day;
					que.push({xnxt,ynxt});
					dis[xnxt][ynxt]=dis[x][y]+1;
				}
			}
		}
	}
}

ll vis1[2005][2005],day1=1;
void jalan(int x,int y){
	vis1[x][y]=day1;
	int xnow=nxt[x][y].ex,ynow=nxt[x][y].ye;
	cout<<x<<" "<<y<<" awal"<<endl;
	if(xnow!=0 && ynow!=0 && vis1[xnow][ynow]!=day1){
		jalan(xnow,ynow);
		
	}
	else{
		ansx=x;
		ansy=y;
	}
}

queue<pii> qu;
void cari(int xi,int yi){
	while(!qu.empty()){
		qu.pop();
	}
	qu.push({xi,yi});
	while(!qu.empty()){
		int x=qu.front().fi;
		int y=qu.front().se;
		qu.pop();
		if(c[x][y]=='X' && x!=xi && y!=yi){
			day1++;
			jalan(x,y);
			return;
		}
		else{
			for(int i=0;i<4;i++){
				int xnxt=x+dx[i];
				int ynxt=x+dy[i];
				if(0<xnxt && 0<ynxt && xnxt<=n && ynxt<=m && !vis[xnxt][ynxt]){
					vis[xnxt][ynxt]=true;
					qu.push({xnxt,ynxt});
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>s;
	cin>>n>>m>>k>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
			if(c[i][j]=='X'){
				ikan.push_back({i,j});
			}
		}
	}
	day=0;
	for(int i=0;i<(int)ikan.size();i++){
		day++;
		int x=ikan[i].fi;
		int y=ikan[i].se;
		//cout<<x<<" "<<y<<endl;
		bfs(x,y);
		//cout<<nxt[x][y].ex<<" "<<nxt[x][y].ye<<endl;
	}
	memset(vis,0,sizeof(vis));
	day=0;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		day++;
		cari(x,y);
		nxt[x][y].ex=ansx;
		nxt[x][y].ye=ansy;
		cout<<ansx<<" "<<ansy<<endl;
	}


	return 0;
}