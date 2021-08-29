#include <iostream>
using namespace std;

int a,b,res,div;

int main(){
	cin>>a>>b;
	int sum=a;
	while(a>=b){
		div=a/b;
		sum=sum+div;
		a=div+a%b;
	}
	cout<<sum<<endl;
}
