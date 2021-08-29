#include <iostream>
using namespace std;

int n,m,a,b,x,y;

int main(){
	cin>>n>>m>>a>>b;
	if(n<m){
		x=b;
		y=n*a;
	}
	else if(n>m){
		x=n/m*b + (n%m)*a;
		y=n*a;
	}
	else{
		x=b;
		y=a;
	}
	
	if(x<y){
		cout<<x<<endl;
	}
	else{
		cout<<y<<endl;
	}
	return 0;
}
