#include <bits/stdc++.h>
using namespace std;

int t,n,a[200],b[10010],sum,maks,temp,ans;
bool p[10010];

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		sum=0;
		memset(b,0,sizeof(b));
		memset(p,false,sizeof(p));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				temp=a[i]+a[j];
				b[temp]++;
			}
		}
		for(int i=1;i<=10000;i++){
			if(b[i]>maks){
				maks=b[i];
				ans=i;
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				temp=a[i]+a[j];
				if(temp==ans && !p[i] && !p[j]){
					sum++;
					p[i]=true;
					p[j]=false;
					break;
				}
			}
		}
		cout<<2*sum<<endl;
	}
	return 0;
}