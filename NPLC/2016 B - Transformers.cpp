#include <bits/stdc++.h>
using namespace std;


int memo[10010],t,k[10010],x;
string s,res;

int fib(int x){
	if(x<=2){
		return 1;
	}
	else if(memo[x]!=0){
		return memo[x];
	}
	else{
		memo[x]=fib(x-1)+fib(x-2);
	}
	return memo[x];
}

int main(){
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>s;
		for(int i=0;i<=s.length()-1;i++){
			if('A'<=s[i] && s[i]<='Z'){
				x=s[i]-'A'+1;
				k[i]=fib(x);
			}
			else if('a'<=s[i] && s[i]<='z'){
				x=s[i]-'a'+1;
				k[i]=fib(x);
			}
			else if('0'<=s[i] && s[i]<='9'){
				x=s[i]-'0';
				k[i]=fib(x);
			}
		}
		for(int i=0;i<=s.length()-1;i++){
			res="";
			while(k[i]>0){
				if(k[i]%10==0){
					res='z'+res;
				}
				else{
					res=char((k[i]%10)+'a'-1)+res;
				}
				k[i]/=10;
			}
			cout<<res;
		}
		cout<<endl;
	}
	return 0;
}