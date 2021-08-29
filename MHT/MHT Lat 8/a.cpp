#include <iostream>
using namespace std;

long long n;

int factorial(int x){
	if(x<=1){
		return 1;
	}
	else{
		return x*factorial(x-1);
	}
}

int main(){
	cin>>n;
	cout<<factorial(n)<<endl;
}