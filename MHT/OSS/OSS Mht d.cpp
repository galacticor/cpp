#include <iostream>
using namespace std;

int main(){
	int k2,k3,k5,k6,x,y;
	cin>>k2>>k3>>k5>>k6;
	int min,min1;
	
	min=k2;
	if(k2<min){
		min=k2;
	}
	if(k5<min){
		min=k5;
	}
	if(k6<min){
		min=k6;
	}
	k2=k2-min;
	min1=k2;
	if(k2<min1){
		min1=k2;
	}
	if(k3<min1){
		min1=k3;
	}
	x=256*min;
	y=32*min1;
	cout<<x+y<<endl;
	return 0;
}
