=#include <bits/stdc++.h>
using namespace std;

int n,a[100010],sum,x,ans,res;

void binser(int x){
	int lo=1,hi=n,mid;
	ans=0;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(a[mid]>x){
			ans=mid;
			hi=mid-1;m,.
		}
		else{
			lo=mid+1;
		}
	}
}

int main(){
	while(cin>>n){
		if(n==0){
			break;
		}
		res=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n-1;j++){
				x=a[i]+a[j];
				ans=0;
				binser(x);
				if(ans!=0){
					res=res+n-ans+1;
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
}