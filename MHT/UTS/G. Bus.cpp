#include <bits/stdc++.h>
using namespace std;

long long mins,sum,res,n,a[200010];

int main(){
	cin>>n;
	mins=2000000001;
	sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		res=abs(a[i]-a[i-1]);
		if(res<mins){
			mins=res;
			sum=0;
		}
		if(res==mins){
			sum++;
		}
	}
	cout<<mins<<" "<<sum<<endl;
}