#include <iostream>
using namespace std;

int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=n-i;j>=1;j--){
			cout<<" ";
		}
		for(int j=1;j<=2*i-1;j++){
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}