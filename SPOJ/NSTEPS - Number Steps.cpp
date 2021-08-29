#include <bits/stdc++.h>
using namespace std;

int n,res,x,y;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(x==y){
			if(x%2==0){
				res=x+y;
			}
			else{
				res=x+y-1;
			}
		}
		else{
			if(x-y==2){
				if(x%2==0){
					res=x+y;
				}
				else{
					res=x+y-1;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}