#include <bits/stdc++.h>
using namespace std;

int n,t,psum[100010],maks,ans,q,a;

void binser(int x){
	int low=1,hi=n,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		if(psum[mid]<=x){
			ans=mid;					//UNTUK MENCARI NILAI TERBESAR YANG <=X
			low=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a;
		psum[i]=a+psum[i-1];
	}
	for(int ki=1;ki<=n;ki++){
		q=psum[ki-1]+t;
		binser(q);
		ans=ans-ki+1;
		if(ans>maks){
			maks=ans;
		}
	}
	cout<<maks<<endl;
	return 0;
}