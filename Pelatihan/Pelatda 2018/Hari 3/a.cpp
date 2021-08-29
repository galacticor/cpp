#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a[110];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
