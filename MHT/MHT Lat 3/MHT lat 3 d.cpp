#include <iostream>
using namespace std;

int main(){
	int sum,s,t,n,p;
	cin>>n;
	t=2;
	for(int i=1;i<=n;i++){
		t=t+t-1;
	}
	cout<<t*t<<endl;
	return 0;
}
