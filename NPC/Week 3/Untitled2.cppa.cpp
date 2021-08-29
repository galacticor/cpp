#include <bits/stdc++.h>
using namespace std;

long long n,k,res,t,j,a[100010],berat;


int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		berat=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		j=1;
		sort(a+1,a+n+1);
		berat=a[1];
		while(berat<=k && j<=n){
			j++;
			berat=berat+a[j];
		}
		cout<<j-1<<endl;
	}
	return 0;
}
