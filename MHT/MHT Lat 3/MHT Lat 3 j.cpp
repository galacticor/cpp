#include <iostream>
using namespace std;

long long a,b,t,bx,ax,res;


int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b;
		if(a%3==0){
			ax=a/3*2;
		}
		else if(a%3==2){
			ax=a/3*2+1;
		}
		else{
			ax=a/3*2;
		}
		if(b%3==0){
			bx=b/3*2;
		}
		else if(b%3==2){
			bx=b/3*2+1;
		}
		else{
			bx=b/3*2;
		}
		if(a%3==0){
			res=bx-ax+1;
		}
		else{
			res=bx-ax;
		}
		cout<<"Case "<<i<<": "<<res<<endl;
	}
	return 0;
}
