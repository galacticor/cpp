#include <bits/stdc++.h>
using namespace std;

long long n,x[100010],y[100010],mins,ans1,ans2;
long double ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    mins=1000000000000;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=hypot(x[i]-x[j],y[i]-y[j]);
			if(ans<=mins){
				mins=ans;
				ans1=i;
				ans2=j;
			}
		}
	}
	cout<<ans1<<" "<<ans2<<endl;

	return 0;
}