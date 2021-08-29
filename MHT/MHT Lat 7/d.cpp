#include <bits/stdc++.h>
using namespace std;

int n,k,a,ans,psum[100010];

void binser(int x){
	int lo=1,hi=n,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(b[mid]<=x){
			ans=mid;					
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

void

int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a;
		psum[i]=psum[i-1]+a;
	}
	for(int i=1;i<=n;i++){
		ki=i;
		
	}
	cout<<ans<<endl;
}


