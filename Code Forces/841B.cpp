#include <iostream>
using namespace std;

long long n,a,x;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a%2==1){
			x++;
		}
	}
	if(x%2==1){
		cout<<"First"<<endl;
	}
	else{
		if(x==0){
			cout<<"Second"<<endl;
		}
		else{
			cout<<"First"<<endl;
		}
	}
	return 0;
}
