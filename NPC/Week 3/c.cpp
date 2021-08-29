#include <bits/stdc++.h>
using namespace std;

int n,m,b[100010],a[100010];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	m=n/2;
	if(n%2!=0){
		for(int i=1;i<=m;i++){
			b[i]=a[i]+a[n-i];
		}
		b[m+1]=a[n];
		sort(b+1,b+m+2);
		for(int i=m+1;i>=2;i--){
			cout<<b[i]<<" "<<"->"<<" ";
		}
		cout<<b[1]<<endl;
	}
	else{
		for(int i=1;i<=m;i++){
			b[i]=a[i]+a[n-i+1];
		}
		sort(b+1,b+m+1);
		for(int i=m;i>=2;i--){
			cout<<b[i]<<" "<<"->"<<" ";
		}
		cout<<b[1]<<endl;
	}
	return 0;
}