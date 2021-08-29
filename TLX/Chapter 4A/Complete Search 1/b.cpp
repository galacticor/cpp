#include <bits/stdc++.h>
using namespace std;
 
bool visited[100][100],aman;
int n,m,t;
string s[100],temp;
 
void flood(int x,int y){
	if(x>0 x<=m && y<=n && y>0 && !visited[x][y] && s[x][y]==' '){
		visited[x][y]=true;
		s[x][y]='*';
		flood(x-1,y);
		flood(x+1,y);
		flood(x,y+1);
		flood(x,y-1);
	}
}

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		getline(cin,temp);
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++){
				visited[i][j]=false;
				s[i][j]=' ';
			}
		}
		for(int i=0;i<=n;i++){
			getline(cin,temp);
			for(int j=0;j<=m;j++){
				s[i][j]=temp[j-1];
			}
		}
		aman=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=' '){
					aman=true;
				}
			}
		}
		if(aman){
			cout<<"YA"<<endl;
		}
		else{
			cout<<"TIDAK"<<endl;
		}
	}
	return 0;
}