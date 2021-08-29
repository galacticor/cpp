#include <bits/stdc++.h>
using namespace std;

long long res,maks,mins,a[1000010],n,x1,xn;

int main(){
	cin>>n;
	maks=-1;
	mins=9999999999;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maks){
			maks=a[i];
		}
		if(a[i]<mins){
			mins=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==mins){
			x1++;
		}
		if(a[i]==maks){
			xn++;
		}
	}
	if(maks==mins){
		res=n*(n-1)/2;
	}
	else{
		res=xn*x1;
	}
	cout<<maks-mins<<" ";
	cout<<res<<endl;
	return 0;
}
