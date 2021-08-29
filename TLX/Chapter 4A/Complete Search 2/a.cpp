#include <bits/stdc++.h>
using namespace std;

int a[50][50],n,m,b,k,sum;
bool visited[50][50];

void flood(int x,int y){
	if(x>=0 && x<=m-1 && y<=n-1 && y>=0 && !visited[x][y] && a[x][y]==a[b][k]){
		visited[x][y]=true;
		sum++;
		flood(x-1,y);
		flood(x+1,y);
		flood(x,y+1);
		flood(x,y-1);
	}
}

int main(){
	cin>>m>>n;
	for(int i=0;i<=m-1;i++){
		for(int j=0;j<=n-1;j++){
			cin>>a[i][j];
		}
	}
	cin>>b>>k;
	flood(b,k);
	cout<<sum*(sum-1)<<endl;
	return 0;
}