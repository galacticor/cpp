#include <iostream>
#include <algorithm>
using namespace std;

int n,m,a[100010],b[100010],ans,q;
void binser(int x){
	int l=1,r=n;
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(x<=b[mid]){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]+b[i-1];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>q;
		binser(q);
		cout<<ans<<endl;
	}
}
