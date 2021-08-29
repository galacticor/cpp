#include <bits/stdc++.h>
using namespace std;

long long x,y,a[100010],xi,ans,xii,z,sum;

void binser(int d,int c){
	int lo=c,hi=x,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(a[mid]<=d){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

int main(){
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	for(int i=1;i<=x-2;i++){
		ans=0;
		binser(a[i]+y,i+1);
		xi=ans-i;
		if(xi>1){
			sum+=xi*(xi-1)/2;
		}
		
		
	}
	
	cout<<sum<<endl;
	return 0;
}