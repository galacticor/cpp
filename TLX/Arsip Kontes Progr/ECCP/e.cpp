#include <bits/stdc++.h>
using namespace std;

int t,n,a[100010],sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		sort(a+1,a+1+n);
		for(int j=n;j>=2;j-=3){
			sum+=a[j];
		}
		cout<<sum<<endl;
	}

	return 0;
}