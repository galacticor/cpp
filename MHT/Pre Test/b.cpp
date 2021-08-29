#include <iostream>
#include <stdlib.h>
using namespace std;

int a,b,c,s,res,x,maks,mins;

int main(){
	cin>>a>>b>>c;
	maks=-1;
	mins=99999999;
	if(a>maks){
		maks=a;
	}
	if(b>maks){
		maks=b;
	}
	if(c>maks){
		maks=c;
	}
	if(a<mins){
		mins=a;
	}
	if(b<mins){
		mins=b;
	}
	if(c<mins){
		mins=c;
	}
	
	cout<<maks-mins<<endl;
	return 0;
}
