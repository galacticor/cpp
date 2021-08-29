#include <bits/stdc++.h>
using namespace std;

int a[50][50],n,m,b,k,sum,p,q,res,maks;
bool visited[50][50];

void flood(int x,int y){
	if(x>=0 && x<=m-1 && y<=n-1 && y>=0 && !visited[x][y] && a[x][y]==a[p][q]){
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
	for(int i=0;i<=m-1;i++){
		for(int j=0;j<=n-1;j++){
			sum=0;
			p=i;
			q=j;
			if(!visited[p][q]){
				flood(p,q);
			}
			res=sum*(sum-1);
			if(res>maks){
				maks=res;
			}
		}
	}
	cout<<maks<<endl;
	return 0;
}