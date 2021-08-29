#include <iostream>
#include <stdlib.h>
using namespace std;

long long n,k,w,x,res;

int main(){
	cin>>k>>n>>w;
	x=0;
	for(int i=1;i<=w;i++){
		x=x+i;
	}
	if(n>x*k){
		res=0;
	}
	else{
		res=abs(n-x*k);
	}
	cout<<res<<endl;
	return 0;
}
