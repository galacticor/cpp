#include <bits/stdc++.h>
using namespace std;

int a[100][100],b[100][100],p,q,res,m,n,sum,maks,sum1,ans,z;
bool visit1[100][100],visit[100][100],con;

void flood(int x,int y){
	if(0<x && 0<y && x<=m && y<=n && !visit[x][y] && b[x][y]==b[p][q]){
		visit[x][y]=true;
		sum++;
		flood(x-1,y);
		flood(x+1,y);
		flood(x,y-1);
		flood(x,y+1);
	}
}

void flood1(int x,int y){
	if(0<x && 0<y && x<=m && y<=n && !visit1[x][y] && b[x][y]==z){
		visit1[x][y]=true;
		sum1++;
		b[x][y]=0;
		flood1(x-1,y);
		flood1(x+1,y);
		flood1(x,y-1);
		flood1(x,y+1);
	}
}

void tes(){
	con=true;
	maks=0;
	while(con){
		con=false;
		for(int i=2;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(b[i][j]==0 && b[i-1][j]!=0){
					con=true;
					swap(b[i][j],b[i-1][j]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sum=0;
			if(!visit[i][j] && b[i][j]!=0){
				p=i;
				q=j;
				flood(p,q);
			}
			maks=max(maks,sum);
		}
	}
}

int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	}
	for(int k=1;k<=m;k++){
		for(int l=1;l<=n;l++){
			sum1=0;
			if(!visit1[k][l] && b[k][l]!=0){
				p=k;
				q=l;
				z=b[p][q];
				flood1(p,q);
				tes();
				res=maks*(maks-1)+sum1*(sum1-1);
				ans=max(ans,res);
				for(int i=1;i<=m;i++){
					for(int j=1;j<=n;j++){
						visit[i][j]=false;
						b[i][j]=a[i][j];
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;

}