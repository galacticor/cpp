#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> L[100];
bool visited[100];

void dfs(int a){
	visited[a]=true;
	cout<<a<<endl;
	for (int i=0;i<L[a].size();i++){
		if(! visited[L[a][i]]){
			dfs(L[a][i]);
		}
	}
}

int a,b,v,e;

int main(){
	cin>>v>>e;
	for(int i=0;i<e;i++){
		cin>>a>>b;
		L[a].push_back(b);
		L[b].push_back(a);
	}
	for(int i=1;i<=v;i++){
		sort(L[i].begin(),L[i].end());
	}
	dfs(1);
	return 0;
}
