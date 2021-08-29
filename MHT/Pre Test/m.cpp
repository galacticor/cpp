#include <iostream>
using namespace std;

long long t,n,sum,temp,pow,x;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		pow=n%10;
		n=n/10;
		x=n;
		temp=1;
		for(int i=1;i<=pow;i++){
			temp=temp*x;
		}
		sum=sum+temp;
	}
	cout<<sum<<endl;
}
