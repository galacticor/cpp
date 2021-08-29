#include <bits/stdc++.h>
using namespace std;

int n;
bool p[100010];
string s[100010];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		p[i]=false;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[i]==s[j] && !p[j]){
				p[j]=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}