#include <bits/stdc++.h>
using namespace std;

int n,k,a[110][110];

int main(){
	cin>>n>>k;
	if(k>n*n){
		cout<<"-1"<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			if(k>=1){
				a[i][i]=1;
				k--;	
			}
			for(int j=i+1;j<=n;j++){
				if(k>=2){
					k-=2;
					a[i][j]=1;
					a[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	
	return 0;
}