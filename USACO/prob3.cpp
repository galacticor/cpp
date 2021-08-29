#include <bits/stdc++.h>
using namespace std;

int n,a[100010],x,temp,temp2;

int main(){
	freopen("outofplace.in","r",stdin);
	freopen("outofplace.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=1000001;
	for(int i=1;i<=n-1;i++){
		if(a[i]>a[i+1]){
			temp2=i;
			break;
			
		}
	}
	if(a[temp2]<=a[temp2+2]){
		x=a[temp2+1];
		for(int i=temp2;i>=1;i--){
			if(a[i]!=a[i-1] && a[i]>x){
				temp++;
			}
		}
		cout<<temp<<endl;
	}
	else{
		x=a[temp2];
		for(int i=temp2+1;i<=n;i++){
			if(a[i]!=a[i+1] && a[i]<x){
				temp++;
			}
		}
		cout<<temp<<endl;
	}
	
	return 0;
}