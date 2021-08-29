#include <bits/stdc++.h>
using namespace std;

int n,a[1010],t,b;
bool p[1010],q;
string s;

void permutasi(int deep){
	if(deep>n){
		for(int i=1;i<=n;i++){
			cout<<s[a[i]];
		}
		cout<<endl;
	}
	else{
		for(int i=0;i<=b-1;i++){
			if(!p[i]){
				p[i]=true;
				a[deep]=i;
				permutasi(deep+1);
				p[i]=false;
			}
		}
	}
}

int main(){
	cin>>t;
	if(t<=5){
		for(int k=1;k<=t;k++){
			cin>>s>>n;
			q=false;
			memset(p,false,sizeof(p));
			b=s.length();
			for(int i=0;i<=b-1;i++){
				if((s[i]<'a' || 'z'<s[i]) && ('A'>s[i] || s[i]>'Z') && (s[i]<'0' || s[i]>'9')){
					q=true;
				}
			}
			if(!q && b<=6 && 2<=n && n<=b ){
				permutasi(1);
			}
			else{
				cout<<"ERROR"<<endl;
			}
			
		}
	}
		
	return 0;
}