#include <bits/stdc++.h>
using namespace std;

int a[1000010],mid,lo,hi,ans;
string s;

int main(){
	hi=1000000;
	for(int i=1;i<=1000000;i++){
		a[i]=i;
	}
	while(lo<hi){
		mid=(lo+hi+1)/2;
		cout<<a[mid]<<endl;
		cin>>s;
		if(s==">="){
			ans=mid;
			lo=mid;
		}
		else{
			hi=mid-1;
		}
	}
	cout<<"! "<<ans<<endl;
	return 0;
}