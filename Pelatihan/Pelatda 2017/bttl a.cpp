#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int a,b,t,result;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b;
		result=gcd(a,b);
		cout<<a/result * b/result<<endl;
	}
	return 0;
}
