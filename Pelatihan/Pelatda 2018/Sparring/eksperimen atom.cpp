#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>a;
		maks1=max(maks1,a);
		maks2=max(maks2,l-a);
	}
	ans=max(maks2,maks1);
	cout<<ans<<endl;

	return 0;
}