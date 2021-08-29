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

vi v;

void dfs(){
	visited[a]=true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		cin>>n>>p;
		for(int i=1;i<=p;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		memset(col,-1,sizeof(col));
		for(int i=0;i<n;i++){
			if(col[i]==-1){
				col[i]=0;
			}
			for(int j=0;j<v[i].size();j++){
				col[j]=col[i]+1;
			}
		}

	}

	return 0;
}