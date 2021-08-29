#include <bits/stdc++.h>
using namespace std;

int n,a[100010],sum,diff;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]<=a[i-1]){
			diff=a[i-1]-a[i];
			a[i]=a[i]+diff+1;
			sum=sum+diff+1;
		}
	}
	cout<<sum<<endl;
	return 0;
}
