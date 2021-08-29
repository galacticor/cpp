#include <bits/stdc++.h>
using namespace std;

long long t,n,a[100010],y,x,k,l,sum;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		sum=0;
		l=0;
		k=0;
		y=n;
		for(int j=1;j<=y;){
			if(a[j]==a[y]){
				j++;
				y--;
			}
			else if(a[j]<a[y]){
				j++;
				a[j]+=a[j-1];
				sum++;
			}
			else{
				y--;
				a[y]+=a[y+1];
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}