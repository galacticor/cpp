#include <bits/stdc++.h>
using namespace std;

int c[100][100],cs,p,q,resx,resy,m,n,sum,res,maks;
bool visit1[100][100],visit[100][100],con;

void flood(int x,int y){
	if(0<x && 0<y && x<=m && y<=n && !visit[x][y] && c[x][y]==c[p][q]){
		visit[x][y]=true;
		sum++;
		flood(x-1,y);
		flood(x+1,y);
		flood(x,y-1);
		flood(x,y+1);
	}
}

void flood1(int x,int y){
	if(0<x && 0<y && x<=m && y<=n && !visit1[x][y] && c[x][y]==cs){
		visit1[x][y]=true;
		c[x][y]=0;
		flood1(x-1,y);
		flood1(x+1,y);
		flood1(x,y-1);
		flood1(x,y+1);
	}
}

int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			visit[i][j]=false;
			visit1[i][j]=false;
		}
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sum=0;
			if(!visit[i][j]){
				p=i;
				q=j;
				flood(p,q);
			}
			if(sum>maks){
				maks=sum;
				resx=i;
				resy=j;
			}
		}
	}
	cs=c[resx][resy];
	flood1(resx,resy);
	con=true;
	while(con){
		con=false;
		for(int i=2;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(c[i][j]==0 && c[i-1][j]!=0){
					con=true;
					swap(c[i][j],c[i-1][j]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(c[i][j]==0){
				cout<<".";
			}
			else{
				cout<<c[i][j];
			}
			if(j<n){
				cout<<" ";
			}
			
		}
		cout<<endl;
	}

}