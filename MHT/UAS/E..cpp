#include <bits/stdc++.h>
using namespace std;

int n,m,xw,xb;
char s[110][110];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.'){
				if(i%2==0){
					if(j%2==0){
						s[i][j]='B';
					}
					else{
						s[i][j]='W';
					}
				}
				else{
					if(j%2==0){
						s[i][j]='W';
					}
					else{
						s[i][j]='B';
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<s[i][j];
		}
		cout<<endl;
	}
}