#include <iostream>
using namespace std;

long long n,res,i;

int main(){
	cin>>n;
	if(n%3==0){
		cout<<n/3 * 2<<endl;
	}
	else {
		cout<<n/3 * 2 + 1<<endl;
	}
	return 0;
}
