#include <bits/stdc++.h>
using namespace std;

long long n,v2[10010],v1[10010],ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>v2[i];
	}
	sort(v1+1,v1+1+n);
	sort(v2+1,v2+1+n);
	for(int i=1;i<=n;i++){
		ans=ans+v1[i]*v2[n-i+1];
	}
	cout<<ans<<endl;
	return 0;

}