#include <bits/stdc++.h>
using namespace std;

int n,k,a[100010],q,res,ans;

void binser(int x){
	int low=1,hi=n,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		if(a[mid]==x){
			ans=mid;
			break;
		}
		else if(x<a[mid]){
			hi=mid-1;
		}
		else if(x>a[mid]){
			low=mid+1;
		}
	}
}

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q=a[i]+k;
		ans=0;
		binser(q);
		if(ans!=0){
			res++;
		}
	}
	cout<<res<<endl;
}
