#include <iostream>
using namespace std;

int n,a[1000010],b[1000010],maks,res;

int main(){
	cin>>n;
	maks=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(b[a[i]]>maks){
			maks=b[a[i]];
			res=a[i];
		}
		
	}
	cout<<res<<endl;
	return 0;
}
