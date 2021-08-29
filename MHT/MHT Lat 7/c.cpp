#include <bits/stdc++.h>
using namespace std;

int n,t,a[100010],q,ans;

void binser(int x){
	int low=1,hi=n,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		if(a[mid]<=x){
			ans=mid;				
			low=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>q;
		ans=0;
		binser(q);
		cout<<ans<<endl;
	}

}


