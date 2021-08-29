#include <bits/stdc++.h>
using namespace std;

int n,q,a[100010],b,x,ans,sum;

void binser(int x){
	int lo=1,hi=n,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(a[mid]==x){
			ans=mid;
			break;
		}
		else if(a[mid]<x){
			lo=mid+1;
		}
		else if(a[mid]>x){
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
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>b;
		ans=0,sum=0;
		binser(b);
		if(ans!=0){
			for(int i=ans;i<=n;i++){
				if(a[i]==a[ans]){
					sum++;
				}
			}
			for(int i=ans;i>=1;i--){
				if(a[i]==a[ans]){
					sum++;
				}
			}
			cout<<"Kasus #"<<i<<": "<<sum-1<<endl;
		}
		else{
			cout<<"Kasus #"<<i<<": TIDAK ADA"<<endl;
		}
	}
	return 0;
}