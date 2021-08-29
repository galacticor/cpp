#include <iostream>
using namespace std;

long long t,n,a[100010],m,x,y;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		m=9999999;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(a[j]<m){
				m=a[j];
			}
		}
		x=m*(n-1);
		if(x>0){
			cout<<m*(n-1)<<endl;
		}
		else{
			cout<<m<<endl;
		}
		
	}
	return 0;
}
