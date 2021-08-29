#include <iostream>
using namespace std;

int a,b,c;

int main(){
	cin>>a>>b>>c;
	int x=a+b+c;
	int y=2*a+2*b;
	int p=2*a+2*c;
	int q=2*b+2*c;
	int min=x;
	if(y<min){
		min=y;
	}
	else if(p<min){
		min=p;
	}
	else if(q<min){
		min=q;
	}
	cout<<min<<endl;
	return 0;
}
