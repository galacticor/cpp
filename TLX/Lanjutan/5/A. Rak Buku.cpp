#include <bits/stdc++.h>
using namespace std;

int n,q,a[50000],sum,idx;

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	idx=0;
	while(idx<=n && sum<q){
		idx++;
		sum+=a[n-idx+1];
	}
	cout<<idx<<endl;
	return 0;
}