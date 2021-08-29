#include <bits/stdc++.h>
using namespace std;

int b[1000][1000],p,q,res,n,sum,maks,sum1,ans,z;
bool visit1[1000][1000],visit[1000][1000];

void flood(int x,int y){
	if(0<x && 0<y && x<=n && y<=n && !visit[x][y] && b[x][y]==z){
		visit[x][y]=true;
		sum++;
		flood(x-1,y);
		flood(x+1,y);
		flood(x,y-1);
		flood(x,y+1);
	}
}

void flood1(int x,int y){
	if(0<x && 0<y && x<=n && y<=n && !visit1[x][y] && (b[x][y]==b[p][q] || b[x][y]==z)){
		visit1[x][y]=true;
		sum1++;
		flood1(x-1,y);
		flood1(x+1,y);
		flood1(x,y-1);
		flood1(x,y+1);
	}
}

void tes(){
	maks=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum1=0;
			if(!visit1[i][j]){
				p=i;
				q=j;
				flood1(p,q);
			}
			maks=max(maks,sum1);
		}
	}
}

int main(){
	freopen("multimoo.in","r",stdin);
	freopen("multimoo.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum=0;
			if(!visit[i][j]){
				p=i;
				q=j;
				z=b[p][q];
				flood(p,q);
			}
			maks=max(maks,sum);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			visit[i][j]=false;
		}
	}
	cout<<maks<<endl;
	
	for(int k=1;k<=n;k++){
		for(int l=1;l<=n;l++){
			sum=0;
			if(!visit[k][l]){
				p=k;
				q=l;
				z=b[p][q];
				flood(p,q);
				tes();
				res=maks+sum;
				ans=max(ans,res);
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						visit1[i][j]=false;
					}
				}
			}
		}
	}
	cout<<ans-3<<endl;
	return 0;

}