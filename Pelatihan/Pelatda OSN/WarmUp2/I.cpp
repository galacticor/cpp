#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int x[100005],h[100005],p[5],n,ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	x[0]=-1*(1e9+2);
	for(int i=1;i<=n;i++){
		cin>>x[i]>>h[i];

	}
	for(int i=1;i<=n;i++){
		if(i==n){
			ans++;
		}
		else if(p[i-1]==1){
			if(x[i]-h[i]<=x[i-1]+h[i-1]){
				if(x[i]+h[i]>=x[i+1]){
					p[i]=0;
					continue;
				}
				else{
					ans++;
					p[i]=1;
				}
			}
			else{
				ans++;
				p[i]=2;
			}
		}
		else{
			if(x[i]-h[i]<=x[i-1]){
				if(x[i]+h[i]>=x[i+1]){
					p[i]=0;
					continue;
				}
				else{
					ans++;
					p[i]=1;
				}
			}
			else{
				ans++;
				p[i]=2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}