#include <bits/stdc++.h>
using namespace std;

int t,n,res,ans,a[100010],k,mins;

void binser(int x){
	int lo=1,hi=n,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(a[mid]>=x){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		mins=1000000005;
		sort(a+1,a+n+1);
		if(n==k){
			for(int i=2;i<n;i++){
				res=a[i]-a[i-1];
				if(res<mins){
					mins=res;
				}
			}
		}
		else{
			res=a[n]-a[1]+1;
			for(int i=1;i<=k;i++){
				binser(res);
				res=ans;
				if(res<mins){
					mins=res;
				}
			}
		}
		
		cout<<mins<<endl;
	}
	return 0;
}


