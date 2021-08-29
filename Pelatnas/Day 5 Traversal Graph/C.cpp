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

int n,op[300005],p,val[300005],res[300005],ubah;
vi v[300005],leaf;

void dfs(int now){
	for(int i=0;i<v[now].size();i++){
		int nxt=v[now][i];
		dfs(nxt);
	}
	if(op[now]==0){
		
		val[now]=val[v[now][0]] & val[v[now][1]];
	}
	else if(op[now]==1){
		
		val[now]=val[v[now][0]] | val[v[now][1]];
	}
	else if(op[now]==2){
		
		val[now]=val[v[now][0]] ^ val[v[now][1]];
	}
	else if(op[now]==3){
		
		val[now]=val[v[now][0]] ^ 1;
	}
	
	//cout<<now<<" "<<val[now]<<endl;
}

void cek(int now){
	if(op[now]==0){
		for(int i=0;i<(int)v[now].size();i++){
			if(val[v[now][i^1]]==0) ubah++;
			cek(v[now][i]);
			if(val[v[now][i^1]]==0) ubah--;
		}
	}
	else if(op[now]==1){
		for(int i=0;i<(int)v[now].size();i++){
			if(val[v[now][i^1]]==1) ubah++;
			cek(v[now][i]);
			if(val[v[now][i^1]]==1) ubah--;
		}
	}
	else if(op[now]==2){
		for(int i=0;i<2;i++){
			cek(v[now][i]);
		}
	}
	else if(op[now]==3){
		cek(v[now][0]);
	}
	else{
		if(ubah==0){
			res[now]=val[1]^1;
		}
		else{
			res[now]=val[1];
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p;
		int a,b;
		if(p==0){
			cin>>a>>b;
			op[i]=p;
			v[i].push_back(a);
			v[i].push_back(b);
		}
		else if(p==1){
			cin>>a>>b;
			op[i]=p;
			v[i].push_back(a);
			v[i].push_back(b);
		}
		else if(p==2){
			cin>>a>>b;
			op[i]=p;
			v[i].push_back(a);
			v[i].push_back(b);
		}
		else if(p==3){
			cin>>a;
			op[i]=p;
			v[i].push_back(a);
		}
		else{
			cin>>a;
			op[i]=p;
			val[i]=a;
			leaf.push_back(i);
		}
	}
	dfs(1);
	// for(int i=1;i<=n;i++){
	// 	cout<<val[i]<<" ";
	// }
	// cout<<endl;
	cek(1);
	//sort(leaf.begin(),leaf.end());
	for(int i=0;i<(int)leaf.size();i++){
		cout<<res[leaf[i]];
	}
	cout<<endl;
	return 0;
}