#include <bits/stdc++.h>
using namespace std;

long long n,a[100010];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=2;i<=n;i+=2){
		if(a[i]<a[i-1]){
			swap(a[i],a[i-1]);
		}
		if(a[i]<a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
