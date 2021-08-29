#include <iostream>
using namespace std;

int res,n,k,x;

int main(){
	cin>>n>>k;
	if(n%k==0){
		res=n+k;
	}
	else{
		res=n+k-n%k;
	}
	cout<<res<<endl;
	
}
