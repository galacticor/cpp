#include <iostream>
using namespace std;

int n;
long long memo[100];

long long fibonacci(int x){
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else if(memo[x]!=0){
		return memo[x];
	}
	else{
		memo[x]=fibonacci(x-1)+fibonacci(x-2);
	}
	return memo[x];
}

int main(){
	cin>>n;
	cout<<fibonacci(n)<<endl;
	return 0;
}