#include <bits/stdc++.h>
using namespace std;

long long n,m,a[100010],b[100010],res,k;

int main(){
	cin>>m>>n;
	k=m-1;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cin>>b[j];
		}
		sort(b+1,b+k+1);
		for(int j=1;j<=m;j++){
			if(a[j]!=b[j]){
				res=a[j];
				break;
			}
		}
		cout<<res<<endl;
		k--;
	}
	return 0;
}