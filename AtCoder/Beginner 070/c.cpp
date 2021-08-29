#include <iostream>
using namespace std;

long long n,x,a[100010];

long long gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=a[1]/gcd(a[1],a[2]) * a[2];
	for(int i=3;i<=n;i++){
		x=x/gcd(a[i],x) * a[i];
	}
	cout<<x<<endl;
	return 0;
}
