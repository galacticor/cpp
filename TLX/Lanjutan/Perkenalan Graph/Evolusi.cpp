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

string s[10005],s1,s2;
int n,m,st,fn,tot;
vi v[10005];
std::vector<string> vx;
bool vis[10005],cek[10005];
std::map<string, int> ma;
bool p;
void track(int x){
	for(int i=0;i<(int)v[x].size();i++){
		int nxt=v[x][i];
		if(vis[nxt]){
			cout<<s[nxt]<<endl;
			track(nxt);
		}
	}
}

void cari(int x){
	//cout<<s[x]<<endl;
	if(x==fn){
		cout<<s[st]<<endl;
		p=true;
		track(st);
		return;
	}
	for(int i=0;i<(int)v[x].size();i++){
		int nxt=v[x][i];
		//cout<<nxt<<endl;
		if(!vis[nxt]){
			vis[nxt]=true;
			cari(nxt);
			vis[nxt]=false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	tot=n;
	for(int i=1;i<=m;i++){
		cin>>s1>>s2;
		if(ma.find(s1)==ma.end()){
			ma[s1]=tot;
			s[tot]=s1;
			tot--;
		}
		if(ma.find(s2)==ma.end()){
			ma[s2]=tot;
			s[tot]=s2;
			tot--;
		}
		v[ma[s1]].push_back(ma[s2]);
	}
	// for(int i=1;i<=10;i++){
	// 	cout<<s[i]<<' ';
	// }
	cin>>s1>>s2;
	p=false;
	st=ma[s1];
	fn=ma[s2];
	vis[st]=true;
	cari(st);
	if(!p){
		memset(vis,0,sizeof(vis));
		p=false;
		st=ma[s2];
		fn=ma[s1];
		vis[st]=true;
		cari(st);
	}
	if(!p){
		cout<<"TIDAK MUNGKIN"<<endl;
	}

	return 0;
}