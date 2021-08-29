#include <iostream>
using namespace std;

int n,a,x1,x2,x3,x4,res1,res2,res3,res4,res12,res;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==1){
			x1++;
		}
		if(a==2){
			x2++;
		}
		if(a==3){
			x3++;
		}
		if(a==4){
			x4++;
		}
	}

	if(x3>=x1){
		x1=0;
	}
	else{
		x1=x1-x3;
	}
	res3=x3;
	
	if(x1<4){
		res1=1;
	}
	res1=x1/4;
	x1=x1%4;
	
	res2=x2/2;
	x2=x2%2;
	
	
	if(2*x2<=x1){
		x1=x1-2*x2;
	}
	else{
		x1=0;
	}
	res12=x2;
	if(x1>0){
		x1=1;
	}
	
	res=res1+res2+res3+x4+res12+x1;
	cout<<res<<endl;
	return 0;
}
