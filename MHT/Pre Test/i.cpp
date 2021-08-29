#include <iostream>
using namespace std;

int n,a[1000010],sum;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			sum++;
		}
	}

	if(n==1){
		if(a[n]==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	else if(sum==1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
