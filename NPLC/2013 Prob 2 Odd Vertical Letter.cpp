#include <bits/stdc++.h>
using namespace std;

int x[1010];
string s[1010];

int main(){
	for(int i=1;i<=10;i++){
		getline(cin,s[i]);
		x[i]=s[i].length();
	}
	for(int i=0;i<=x[1];i++){
		for(int j=1;j<=10;j++){
				cout<<s[j][i];
		}
	}
	return 0;
}