#include <bits/stdc++.h>
using namespace std;

int ed[10010][10010],m,n;
string s1,s2;

void min_edit_distance(string s1,string s2){
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0){
				ed[i][j]==j;
			}
			else if(j==0){
				ed[i][j]==i;
			}
			else if(s1[i-1]==s2[j-1]){
				ed[i][j]=ed[i-1][j-1];
			}
			else{
				ed[i][j]=min(ed[i-1][j],ed[i][j-1],ed[i-1][j-1]);
			}
		}
	}
}

int main(){
	cin>>s1>>s2;
	m=s1.length();
	n=s2.length();
	void(s1,s2);
	cout<<ed[m][n]<<endl;
	return 0;
}