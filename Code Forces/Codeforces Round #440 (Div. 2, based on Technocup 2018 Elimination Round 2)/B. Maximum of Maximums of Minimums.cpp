#include <bits/stdc++.h>
using namespace std;

long long maks,mins,a[100010],n,k,res;

int main(){
	cin>>n>>k;
	maks=-1000000003;
	mins=1000000003;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maks){
			maks=a[i];
		}
		if(a[i]<mins){
			mins=a[i];
		}
	}
	if(k==1){
		res=mins;
	}
	else if(k==2){
		if(a[1]>=a[n]){
			res=a[1];
		}
		else{
			res=a[n];
		}
	}
	else if(k>2){
		res=maks;
	}
	cout<<res<<endl;
	return 0;
}