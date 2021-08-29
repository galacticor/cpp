#include <bits/stdc++.h>
using namespace std;

long long n,x[100010],y[100010],ar[100010][100010],temp,ans;

int main(){
	freopen("lifeguards.in","r",stdin);
	freopen("lifeguards.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		for(int j=x[i];j<y[i];j++){
			for(int k=1;k<=n;k++){
				ar[k][j]++;
			}
		}
	}

	for(int i=1;i<=n;i++){
		temp=0;
		for(int j=x[i];j<y[i];j++){
			ar[i][j]--;
		}
		for(int j=1;j<=1000;j++){
			if(ar[i][j]!=0){
				temp++;
			}
		}
		ans=max(temp,ans);
	}
	cout<<ans<<endl;
	return 0;
}