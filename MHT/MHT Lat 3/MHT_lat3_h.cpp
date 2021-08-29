#include <iostream>
using namespace std;

int t,x,y,maks,mini;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>y;
		mini=99999999;
		maks=-1;
		for(int j=1;j<=y;j++){
			cin>>x;
			
			if(x<=mini){
				mini=x;
			}
			if(x>=maks){
				maks=x;
			}
		}
		int res=maks-mini;
		cout<<2*res<<endl;
	}
	return 0;
}
