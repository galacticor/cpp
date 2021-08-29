#include <iostream>
using namespace std;

int n,bef,now,res,diff,a;

int main(){
	cin>>n;
	bef=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		now=a;
		diff=now-bef;
		if(diff>15){
			res=bef+15;
			break;
		}
		bef=now;
	}
	if(n==1){
		if(a>15){
			res=15;
		}
		else{
			res=a+15;
		}
	}
	if(res==0){
		if(90-now>15){
			res=now+15;
		}
		else {
			res=90;
		}
	}
	cout<<res<<endl;
	return 0;
}
