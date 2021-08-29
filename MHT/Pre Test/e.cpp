#include <iostream>
using namespace std;

long long n,k,x;

int main(){
	cin>>n>>k;
	x=n/k;
	if(x%2==0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
	return 0;
}
