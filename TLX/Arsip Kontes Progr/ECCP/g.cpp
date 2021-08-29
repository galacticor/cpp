#include <bits/stdc++.h>
using namespace std;

int t,n,a[100010],sum,x;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>x;
		sum=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		sort(a+1,a+n+1);
		for(int j=1;j<=n;j++){
			if(x<=0){
				break;
			}
			else{
				x-=a[j];
				sum++;
			}
		}
		cout<<sum<<endl;
	}

	return 0;
}