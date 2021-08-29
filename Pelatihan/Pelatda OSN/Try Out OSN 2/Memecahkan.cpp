#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int ans,n,k,maks,a[300010];

bool cek(int x){
	for(int i=1;i<=n;i++){
		int tmp=a[i]/x;
		if(tmp>0){
			if(abs(a[i]-x*tmp)>k){
				return false;
			}
		}
		else{
			if(abs(a[i]-x*tmp)>k){
				return false;
			}
		}
	}
	return true;
}

void binser(){
	int lo=1,hi=maks,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(cek(mid)){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	int mins=1e9;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maks=max(maks,a[i]);
		mins=min(mins,a[i]);
	}
	if(n<20){
		for(int i=mins;i>=1;i--){
			if(cek(i)){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	binser();
	cout<<ans<<endl;
	return 0;
}