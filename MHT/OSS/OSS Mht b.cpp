#include <iostream>
using namespace std;

int n,x,a[100010],p;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>x;
		p=0;
		for(int j=1;j<=n;j++){
			if(x>=a[j]){
				p++;
			}
		}
		cout<<p<<endl;
	}
	return 0;
}
