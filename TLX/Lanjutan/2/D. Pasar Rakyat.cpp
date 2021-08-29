#include <bits/stdc++.h>
using namespace std;

long long t,a[100],ans;

long long gcd(long long x,long long y){
	if(y==0){
		return x;
	}
	else{
		return gcd(y,x%y);
	}
}

long long lcm(long long x,long long y){
	return x*y/gcd(x,y);
}

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	ans=1;
	for(int i=1;i<=t;i++){
		if(ans<a[i]){
			ans=lcm(ans,a[i]);
		}
		else{
			ans=lcm(a[i],ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}