#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

vector <pii> v[50010];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int n,m,now,ans;
pair<int,int> nxt;
pair<int,int> temp;
bool visited[50010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({z,y});
		v[y].push_back({z,x});
	}
	now=1;
	for(int i=0;i<n-1;i++){
		visited[now]=true;
		for(int j=0;j<(int)v[now].size();j++){
			nxt=v[now][j];
			if(!visited[nxt.second]){
				pq.push(nxt);
			}
		}
		temp=pq.top(); pq.pop();
		while(visited[temp.second]){
			temp=pq.top(); pq.pop();
		}
		ans+=temp.first;
		now=temp.second;
	}
	cout<<ans<<endl;
	return 0;
}