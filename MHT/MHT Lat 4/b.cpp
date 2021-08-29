#include <iostream>
using namespace std;

int n,k,a[1000010],kkm,res;

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	kkm=a[k];
	for(int i=1;i<=n;i++){
		if(a[i]>=kkm && a[i]!=0){
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
