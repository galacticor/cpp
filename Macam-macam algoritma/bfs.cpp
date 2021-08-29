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

vector<int> v[100005];
queue<int> q;
bool visited[100005];
int dist[100005];
int s[100005];
int n, m, x, y, k;

void bfs(){
	while(!q.empty()){
		int now = q.front(); q.pop();

		for(int i = 0; i < (int)v[now].size(); i++){
			int next = v[now][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[next] = dist[now] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);


	cin >> n >> m;

	for(int i = 0; i <m; i++){
		cin >>x >>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	cin >> k;
	for(int i=0; i<k;i++){
		cin >> x;
		q.push(x);
		visited[x] = true;
		dist[x] = 0;	
	}
	bfs();

	// Cari maks
	int maks = -1,ans;
	for (int i = 1; i <= n; i++){
		if(dist[i]>maks) {
			maks=dist[i];
			ans=i;
		}
	}

	cout << maks << endl;
	if (maks != -1) cout << ans << endl;

	return 0;
}