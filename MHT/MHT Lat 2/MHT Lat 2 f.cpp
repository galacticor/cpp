#include <iostream>
using namespace std;

int a,b;

int main(){
	cin>>a>>b;
	if(a<b){
		if(a%2==0){
			cout<<"Malvika"<<endl;
		}
		else{
			cout<<"Akshat"<<endl;
		}
	}
	else{
		if(b%2==0){
			cout<<"Malvika"<<endl;
		}
		else{
			cout<<"Akshat"<<endl;
		}
	}
	return 0;
}
