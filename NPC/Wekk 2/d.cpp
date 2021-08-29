#include <iostream>
using namespace std;

long long t,n,j,sum;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		j=1;
		sum=0;
		while(j*j<=n){
			if(n%j==0){
				if(j!=n/j){
					sum=sum+j+n/j;
				}
				else{
					sum=sum+j;
				}
			}
			j++;
		}
		cout<<"Kasus #"<<i<<": "<<sum<<endl;
	}
	return 0;
}
