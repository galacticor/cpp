#include <bits/stdc++.h>
using namespace std;

int n;
double maks,mins,x,sum,ans;

int main(){
	cin>>n;
	mins=10000001;
	maks=-10000001;
	for(int i=1;i<=n;i++){
		cin>>x;
		sum+=x;
		mins=min(mins,x);
		maks=max(maks,x);
	}
	ans=sum/n;
	cout<< fixed << setprecision(2);
	cout<<mins<<" "<<maks<<" "<<ans<<endl;
	return 0;
}