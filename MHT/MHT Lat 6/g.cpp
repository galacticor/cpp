#include <bits/stdc++.h>
using namespace std;

int n,a[100010],x,res;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		x=a[i]-a[i-1];
		if(x>1){
			a[i]=a[i]-x+1;
		}
	}
	res=a[n]+1;
	cout<<res<<endl;
	return 0;
}
