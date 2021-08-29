#include <bits/stdc++.h>
using namespace std;

int n,a,b,j,ans,temp;

int main(){
	cin>>n>>a>>b;
	if(n==a+b){
		cout<<"1"<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			j=n-i;
			temp=10000;
			temp=min(a/i,temp);
			temp=min(b/j,temp);
			ans=max(ans,temp);
		}
		cout<<ans<<endl;
	}
	return 0;
}