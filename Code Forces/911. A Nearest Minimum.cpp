#include <bits/stdc++.h>
using namespace std;

int n,a[100010],ans,mins,sum,temp;

int main(){
	cin>>n;
	mins=1000000001;
	ans=1000000001;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<mins){
			mins=a[i];
			temp=i;
		}
	}
	for(int i=1;i<=n;i++){
		sum++;
		if(i==temp){
			sum=0;
		}
		if(a[i]==mins && i!=temp){
			ans=min(ans,sum);
			sum=0;
		}
	
	}
	cout<<ans<<endl;
	return 0;
}