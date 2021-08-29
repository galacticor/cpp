#include <iostream>
using namespace std;

int n,maks,x,a[1000010];

int main(){
	cin>>n;
	maks=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		x=x+a[i];
		if(a[i]>maks){
			maks=a[i];
		}	
	}
	cout<<n*maks - x<<endl;
	return 0;
}
