#include <bits/stdc++.h>
using namespace std;

int n,a[100010],b[100010],sum,maks,ans,temp;
bool p;

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
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans=0;
		binser(b[i]);
		temp=i-ans;
		maks=max(temp,maks);
	}

	cout<<maks+1<<endl;
	return 0;


}