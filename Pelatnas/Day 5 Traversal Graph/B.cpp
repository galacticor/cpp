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

map<char,int> m;
vi v[10005],urut;
bool vis[10005],cek[10005];
string c[10005];
int n,cnt;
bool adj[50][50];

void dfs(int now){
	vis[now]=true;
	for(int i=0;i<(int)v[now].size();i++){
		int nxt=v[now][i];
		if(!vis[nxt]){
			dfs(nxt);
		}
	}
	urut.push_back(now);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n;
	cnt=1;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int i=0;i<(int)s.length();i++){
			if(m.find(s[i])==m.end()){
				m[s[i]]=cnt;
				c[cnt]=s[i];
				cnt++;
			}
			cek[m[s[i]]]=true;
			if(i>0){
				v[m[s[i]]].push_back(m[s[i-1]]);
				adj[m[s[i]]][m[s[i-1]]]=true;
			}
		}	
	}
	for(int i=0;i<cnt;i++){
		if(!vis[i]) dfs(i);
	}
	string ans="";
	for(int i=0;i<(int)urut.size();i++){
		ans=ans+c[urut[i]];
	}
	for(int i=1;i<(int)ans.length();i++){
		int tmp1=m[ans[i]];
		int tmp2=m[ans[i-1]];
		if(ans[i]<ans[i-1] && !adj[tmp1][tmp2]){
			swap(ans[i],ans[i-1]);
		}
	}
	cout<<ans<<endl;
	


	return 0;
}