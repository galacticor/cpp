#include <bits/stdc++.h>
using namespace std;

int a[50][50],n,m,b,k,sum,p,q,res,maks,temp,res1,res2;
bool visited[50][50],visited1[50][50],x;

void flood(int x,int y){
	if(x>=1 && x<=m && y<=n && y>=1 && !visited[x][y] && a[x][y]==a[p][q]){
		visited[x][y]=true;
		sum++;
		flood(x-1,y);
		flood(x+1,y);
		flood(x,y+1);
		flood(x,y-1);
	}
}

void flood1(int x,int y){
	if(x>=1 && x<=m && y<=n && y>=1 && !visited1[x][y] && a[x][y]==b){
		visited1[x][y]=true;
		a[x][y]=0;
		flood1(x-1,y);
		flood1(x+1,y);
		flood1(x,y+1);
		flood1(x,y-1);
	}
}

int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sum=0;
			p=i;
			q=j;
			if(!visited[i][j]){
				flood(p,q);
				res=sum*(sum-1);
				if(res>maks){
					maks=res;
					res1=p;
					res2=q;
				}
			}
		}
	}
	b=a[res1][res2];
	flood1(res1,res2);
	x=true;
	while(x){
		x=false;
		for(int i=2;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0 && a[i-1][j]!=0){
					x=true;
					swap(a[i][j],a[i-1][j]);
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				cout<<".";
			}
			else{
				cout<<a[i][j];
			}
			if(j<n){
				cout<<" ";
			}
			
		}
		cout<<endl;
	}
	return 0;
}