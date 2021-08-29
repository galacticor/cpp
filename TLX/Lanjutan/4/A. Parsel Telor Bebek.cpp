#include <bits/stdc++.h>
using namespace std;

long long N,a[500000],ans,ans1,ans2,sum,n,m;

void cek(long long x){
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=(x/a[i]);
	}
}


void binserhi(long long x){
	long long low=1,hi=N,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		cek(mid);
		if(sum<=x){
			ans1=mid;			
			low=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

void binserlow(long long x){
	long long low=1,hi=N,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		cek(mid);
		if(sum>=x){
			ans2=mid;			
			hi=mid-1;
		}
		else{
			low=mid+1;
		}
	}
}

int main(){
	cin>>n>>m;
	N=5000000000000000000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	binserlow(m);
	binserhi(m);

	cout<<ans1-ans2+1<<endl;
	return 0;

}