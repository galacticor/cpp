#include <bits/stdc++.h>
using namespace std;

long long n,k,a[10010],maks,sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-k;i++){
		maks=-1;
		for(int j=1;j<=k;j++){
			maks=max(maks,a[i+j]);
		}
		sum+=maks;
	}
	cout<<sum<<endl;
	return 0;
}