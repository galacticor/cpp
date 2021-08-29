#include <iostream>
#include <stdlib.h>
using namespace std;

long long x,y,res,n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		res=0;
		if((abs(x-y)==2 || abs(x-y)==0) && x>=y){
			if(x==y){
				if(x%2==0){
					res=x+y;
				}
				else{
					res=x+y-1;
				}
			}
			else{
				if(x%2==0){
					res=x+y;
				}
				else{
					res=x+y-1;
				}
			}
		}
		if(res!=0){
			cout<<res<<endl;
		}
		else if(x==0 && y==0){
			cout<<"0"<<endl;
		}
		else{
			cout<<"No Number"<<endl;
		}
	}
}
