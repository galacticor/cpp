#include <iostream>
using namespace std;

int n,t,m,x,a[100010],sum;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>m;
		sum=0;
		for(int j=1;j<=m;j++){
			cin>>x;
			sum=sum+a[x];
		}
		cout<<"Kasus #"<<i<<": "<<sum<<endl;
	}
	return 0;
}
