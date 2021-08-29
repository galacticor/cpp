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

pii kota[300005];
int n,m,a,b,maks[300005],mins[300005],pos[300005],bisa[300005];
int atas[300005],bawah[300005],pref[300005];
bool vis1[300005],vis[300005];
vi v1[300005],v[300005];
vector<pair<pii,int>> timur,barat;

void dfstimur(int now){
	vis1[now]=true;
	if(kota[now].fi==0) bisa[now]=true;
	for(int i=0;i<(int)v1[now].size();i++){
		int nxt=v1[now][i];
		if(!vis1[nxt]){
			dfstimur(nxt);
		}
		bisa[now]|=bisa[nxt];
	}
}

void dfsbarat(int now){
	vis[now]=true;
	if(kota[now].fi==a){
		atas[now]=pos[now];
		bawah[now]=pos[now];
		maks[now]=kota[now].se;
		mins[now]=kota[now].se;
	}
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i];
		//cout<<now<<" "<<nxt<<endl;
		if(!vis[nxt]){
			dfsbarat(nxt);
		}
		if(maks[now]<maks[nxt]){
			maks[now]=maks[nxt];
			atas[now]=atas[nxt];
		}
		if(mins[now]>mins[nxt]){
			mins[now]=mins[nxt];
			bawah[now]=bawah[nxt];
		}
	}
}

void init(){
	for(int i=1;i<=n;i++){
		maks[i]=-1;
		mins[i]=1e9;
		atas[i]=-1;
	}
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		kota[i].fi=x;
		kota[i].se=y;
		if(x==0){
			barat.push_back({{y,x},i});
		}
		else if(x==a){
			timur.push_back({{y,x},i});
		}
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back(y);
		v1[y].push_back(x);
		if(z==2){
			v[y].push_back(x);
			v1[x].push_back(y);
		}
	}
	init();
	sort(barat.begin(),barat.end());
	sort(timur.begin(),timur.end());
	for(int i=0;i<(int)timur.size();i++){
		int id=timur[i].se;
		pos[id]=i+1;
		if(!vis1[id]){
			vis1[id]=true;
			dfstimur(id);
		}
	}
	pref[0]=0;
	memset(vis1,false,sizeof(vis1));
	for(int i=0;i<(int)timur.size();i++){
		int id=timur[i].se;
		if(!vis1[id]){
			vis1[id]=true;
			dfstimur(id);
		}
		if(bisa[id]){
			pref[pos[id]]=pref[pos[id]-1]+1;
		}
		else pref[pos[id]]=pref[pos[id]-1];
	}
	for(int i=0;i<(int)barat.size();i++){
		int id=barat[i].se;
		if(!vis[id]){
			vis[id]=true;
			dfsbarat(id);
		}
	}
	memset(vis,false,sizeof(vis));
	for(int i=(int)barat.size()-1;i>=0;i--){
		int id=barat[i].se;
		if(!vis[id]){
			vis[id]=true;
			dfsbarat(id);
		}
		if(atas[id]==-1 ) cout<<"0"<<endl;
		else cout<<pref[atas[id]]-pref[bawah[id]-1]<<endl;
	}

	return 0;
}