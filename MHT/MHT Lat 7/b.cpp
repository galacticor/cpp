#include <bits/stdc++.h>
using namespace std;

int a[100010],ans,n,t,b[100010],q;

void binser(int x ){
	int low=1,hi=n,mid;
	while (low<=hi){
		mid=(low+hi)/2;
		if(b[mid]>=x){				
			ans=mid;
			hi=mid-1;
		}
		else{
			low=mid+1;
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+b[i-1];
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>q;
		binser(q);
		cout<<ans<<endl;
	}
	return 0;
}


