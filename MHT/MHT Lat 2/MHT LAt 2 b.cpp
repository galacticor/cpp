#include <iostream>
using namespace std;

long long n,res;

int main(){
	cin>>n;
	if(n%2==0){
		res=n/2;
	}
	else{
		res=n/2-n;
	}
	cout<<res<<endl;
	return 0;
}
