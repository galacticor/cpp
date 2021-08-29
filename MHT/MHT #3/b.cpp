#include <iostream>
using namespace std;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum+=a;
		if(a%2!=0){
			if(a<mins){
				mins=a;
			}
		}
	}
	if(sum%2!=0){
		sum=sum-mins;
	}
	cout<<sum<<endl;
	
}
