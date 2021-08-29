#include <iostream>
using namespace std;

int x,y,z,maks;

int main(){
	cin>>x>>y>>z;
	maks=-1;
	if(x<y<z){
		if(y-x>maks){
			maks=y-x;
		}
		if(z-y>maks){
			maks=z-y;
		}
		cout<<maks-1<<endl;
	}

}
