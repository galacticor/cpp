#include <bits/stdc++.h>
using namespace std;

int n,q,a,y,prefix[100010],ans;

void binser(int x ){
	int low=1,hi=n,mid;
	while (low<=hi){
		mid=(low+hi)/2;
		if(prefix[mid]>=x){					
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
		cin>>a;
		ans+=a;
		prefix[i]=ans;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>y;
		binser(y);
		cout<<ans<<endl;
	}
	return 0;
}