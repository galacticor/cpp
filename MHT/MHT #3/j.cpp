#include <iostream>
using namespace std;

int n,m,x,a,maks,res;

int main(){
	cin>>n>>m;
	maks=-1;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a%m==0){
			x=a/m;
		}
		else{
			x=a/m+1;
		}
		if(x>=maks){
			maks=x;
			res=i;
		}
		
	}
	cout<<res<<endl;
	return 0;
}
