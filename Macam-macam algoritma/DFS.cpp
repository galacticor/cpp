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

vector<int> v[102];
bool visited[102];

void dfs(int now){
	visited[now] = true;
	cout << now << " ";
	for(int i = 0; i < (int)v[now].size(); i++){
		int next = v[now][i];
		if(!visited[next]){
			dfs(next);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
	
	int n, m, x, y, s;
	cin >> n >> m;

	for(int i = 0; i< m; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	cin >> s;
	dfs(s);
	cout << endl;

	return 0;
}