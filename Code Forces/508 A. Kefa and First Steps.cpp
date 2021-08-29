#include <bits/stdc++.h>
using namespace std;

long long n,a[100010],j,sum,ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	j=1;
	ans=1;
	for(int i=1;i<n;i++){
		sum=1;
		while(a[i]<=a[i+1]){
			i++;
			sum++;
		}
		ans=max(sum,ans);
		sum=1;
	}
	cout<<ans<<endl;
	return 0;

}