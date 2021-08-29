#include <iostream>
using namespace std;

int n,a[100010],p[100010],mins,sum;

int main(){
	cin>>n;
	mins=999999;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>p[i];
	}
	for(int i=1;i<=n;i++){
		if(p[i]<mins){
			mins=p[i];
		}
		sum=sum+mins*a[i];
	}
	cout<<sum<<endl;
	return 0;
}
