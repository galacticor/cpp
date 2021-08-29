#include <bits/stdc++.h>
using namespace std;

string s,s2,temp;
int res,i,n,j,x;

int main(){
	cin>>n;
	cin>>s;
	i=0;
	while(i<=n){
		if(islower(s[i])){
			j=i+1;
			s2=s[i];
			while(j<=n && islower(s[j])){
				if(s2.find(s[j])==-1){
					temp=s[j];
					s2.insert(0,temp);
				}
				j++;
			}
			x=s2.length();
			if(x>res){
				res=x;
			}	
			s2.clear();
		}
		else{
			j=i+1;
		}
		i=j;
	}
	cout<<res<<endl;
}