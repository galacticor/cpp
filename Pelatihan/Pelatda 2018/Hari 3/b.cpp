#include <bits/stdc++.h>
using namespace std;

int t,a,ans,n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a;
			ans=max(a,ans);
		}
		cout<<"Case "<<i<<": "<<ans<<endl;
	}

	return 0;
}