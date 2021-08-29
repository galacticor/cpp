#include <bits/stdc++.h>
using namespace std;

int m,n,sum,maks,res,a[100][100],p,q;
bool visit[100][100]; 

void flood(int x, int y){
	if(0<x && 0<y && x<=m && y<=n && !visit[x][y] && a[x][y]==a[p][q]){
		visit[x][y]=true;
		sum++;
		flood(x-1,y);
		flood(x,y-1);
		flood(x,y+1);
		flood(x+1,y);
	}
}

int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			visit[i][j]=false;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sum=0;
			if(!visited[i][j]){
				p=i;
				q=j;
				flood(p,q);
			}
			maks=max(maks,sum);
		}
	}
	res=maks*(maks-1);
	cout<<res<<endl;
	return 0;
}