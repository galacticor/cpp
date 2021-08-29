#include <iostream>
using namespace std;

int a,b,k,x,y;

int func(int n){
	y=a*n+b;
	if(y<0){
		y=-y;
	}
	x=y;
}

int main(){
	cin>>a>>b>>k>>x;
	if((-5<=a,b,x<=5)and(1<=k<=5)){
		for(int i=1;i<=k;i++){
			func(x);
		}
	}
	cout<<x<<endl;
}
