#include <iostream>
#include <cstring>
using namespace std;

int n,m,i,k,x[110][110],y[110][110],ansi=101,ansj=101;
int check[110][110];
bool z[110][110];

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x[i][j];
			z[i][j]=true;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			int res=1;
			if(z[i-1][j]){
				res=res*x[i-1][j];
			}
			if(z[i][j-1]){
				res=res*x[i][j-1];
			}
			if(z[i+1][j]){
				res=res*x[i+1][j];
			}
			if(z[i][j+1]){
				res=res*x[i][j+1];
			}
			y[i][j]=res;
			if(y[i][j]==k){
				if((j<ansj) || ((j==ansj) && (i<ansi))) {
					ansi = i;
					ansj = j;
				}
			}
		}
	}
	if((ansi==101)&&(ansj==101)){
		cout<<"0"<<' '<<"0"<<endl;
	}
	else{
		cout<<ansi<<' '<<ansj<<endl;
	}
	return 0;
}
