#include <bits/stdc++.h>
using namespace std;

int n,k,a[100010];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[k]<<endl;
	return 0;
}
