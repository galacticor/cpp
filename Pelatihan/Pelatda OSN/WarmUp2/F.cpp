#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,k,a[5],ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	a[1]=k;
	a[2]=k;
	a[3]=k;
	while(a[1]<n || a[2]<n || a[3]<n){
		a[1]=a[2]+a[3]-1;
		sort(a+1,a+4);
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}