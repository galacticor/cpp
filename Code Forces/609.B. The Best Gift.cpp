#include <bits/stdc++.h>
using namespace std;

long long n,m,res,decr,k,a[200010],sum,x;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	res=n*(n-1)/2;
	k=2;
	while(k<=n){
		if(k==n){
			if(a[k]==a[k-1]){
				sum+=2;
				if(sum%2==0){
					x=(sum/2)*(sum-1);
				}
				else{
					x=(sum)*((sum-1)/2);
				}
				decr=decr+x;
			}
			else{
				sum++;
				if(sum%2==0){
					x=(sum/2)*(sum-1);
				}
				else{
					x=(sum)*((sum-1)/2);
				}
				decr=decr+x;
			}
		}
		else if(a[k]==a[k-1]){
			sum++;
		}
		else{
			sum++;
			if(sum%2==0){
					x=(sum/2)*(sum-1);
				}
				else{
					x=(sum)*((sum-1)/2);
				}
			decr=decr+x;
			sum=0;
		}
		k++;
	}
	res=res-decr;
	cout<<res<<endl;
	return 0;
}