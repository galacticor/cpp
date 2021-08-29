#include <bits/stdc++.h>
using namespace std;

int res,n,k,s,d;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>d;
		k=0;
		while(s+d*k<=res){
			k++;
		}
		res=s+d*k;
	}
	cout<<res<<endl;

}