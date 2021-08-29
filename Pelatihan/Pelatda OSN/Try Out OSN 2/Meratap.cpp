#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,a[100010],x[100010],ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x[1]=1; x[2]=2;
	for(int i=3;i<=n;i++){
		if(a[i]>x[i-1]){
			for(int j=3;j<i;j++){
				x[j]++;
			}
			x[i]=x[i-1]+1;
		}
		else if(a[i]==0){
			x[i]=x[i-1];
		}
		else{
			if(a[i]==x[i-1]){
				x[i]=x[i-1]+1;
			}
			else{
				x[i]=x[i-1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=(x[i]-a[i]-1);
	}
	cout<<ans<<endl;
	return 0;
}