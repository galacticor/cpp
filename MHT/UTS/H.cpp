#include <bits/stdc++.h>
using namespace std;

int ans,n,k,a[200010],j,l,sum,res,sum1;

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
		int x=a[i];
		sum=0;
		sum1=0;
		ans=0;
		binser(x*k);
		if(ans>0){
			j=ans;
			while(a[ans]==a[ans-1] && ans>=1){
				sum++;
				ans--;
			}
			while(a[j]==a[j+1] && j<=n){
				sum++;
				j++;
			}
			sum++;
		}
		ans=0;
		binser(x*k*k);
		if(ans>0){
			l=ans;
			while(a[ans]==a[ans-1] && ans>=1){
				sum1++;
				ans--;
			}
			while(a[l]==a[l+1] && l<=n){
				sum1++;
				l++;
			}
			sum1++;
		}
		cout<<sum<<" "<<sum1<<endl;
		res=res+sum*sum1;
	}
	cout<<res<<endl;
	return 0;
}