#include <bits/stdc++.h>
using namespace std;

int n,k,a[500010],temp,ans,ansj,ansi;

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1, zero=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			zero++;
		}
		while(zero>k){
			if(a[j]==0){
				zero--;
			}
			j++;
		}
		temp=i-j+1;
		if(temp>ans){
			ans=temp;
			ansj=j;
			ansi=i;
		}
	}
	cout<<ans<<endl;
	for(int i=ansj;i<=ansi;i++){
		a[i]=1;
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}