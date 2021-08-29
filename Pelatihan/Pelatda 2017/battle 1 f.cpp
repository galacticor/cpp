#include <iostream>
using namespace std;

long long t,a[10000010],temp;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	for(int i=1;i<=t/2;i++){
		if(i%2!=0){
			temp=a[i];
			a[i]=a[t-i+1];
			a[t-i+1]=temp;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
