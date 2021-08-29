#include <iostream>
using namespace std;

long long n;

void biner(int x){
	int rem;
	if(x<=1){
		cout<<x;
		return;
	}
	else{
		rem=x%2;
		biner(x/2);
		cout<<rem;
	}
}

int main(){
	cin>>n;
	biner(n);
	cout<<endl;
	return 0;
}
