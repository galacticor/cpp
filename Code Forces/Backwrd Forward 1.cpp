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
		for(int j=1;j<=n/2;j++){
			while(a[j]!=a[y]){
				while(a[j]<a[y]){
					k++;
					a[j]+=a[j+k];
					a[j+k]=0;
					sum++;
				}

				while(a[j]>a[y]){
					l++;
					a[y]+=a[y-l];
					a[y-l]=0;
					sum++;
				}
			}
			j+=k;
			y-=l;
			k=0;
			l=0;
		}
		cout<<sum<<endl;
	}
	return 0;
}