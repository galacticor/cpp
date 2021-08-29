#include <bits/stdc++.h>
using namespace std;

double a[100010],sum,mean,var,stnd;
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	mean=sum/n;
	for(int i=1;i<=n;i++){
		var=var+(a[i]-mean)*(a[i]-mean);
	}
	
	var=var/n;
	stnd=sqrt(var);
	cout<<fixed<<setprecision(4);
	cout<<mean<<endl;
	cout<<var<<" "<<stnd;
	return 0;
}
