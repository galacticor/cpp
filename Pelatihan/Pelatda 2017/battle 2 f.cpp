#include <iostream>
using namespace std;

int n,b,sum,res,a[10000010],x;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b=0;
	int j=1;
	while(b!=j){
		b=a[j];
		b=a[b];
		sum++;
	}
	if(sum%2==0){
		res=sum/2;
	}
	else{
		res=sum;
	}
	cout<<res<<endl;
}
