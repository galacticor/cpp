#include <bits/stdc++.h>
using namespace std;

string s,que;
bool p,q;
int k;

int main(){
	cin>>s;
	cin>>que;
	if(s.length()-que.length()!=1){
		cout<<"Wah, tidak bisa :("<<endl;
	}
	else{
		while(!p && k<s.length()){
			if(s[k]!=que[k]){
				p=true;
				break;
			}
			k++;
		}
		if(p){
			for(int i=k+1;i<=s.length()-1;i++){
				if(s[i]!=que[k]){
					q=true;
				}
				k++;
			}
		}
		if(!q){
			cout<<"Tentu saja bisa!"<<endl;
		}
		else{
			cout<<"Wah, tidak bisa :("<<endl;
		}
	}
	return 0;
}