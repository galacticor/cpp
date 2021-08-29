#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,a[200010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n/2;i++){
		if(i%2==1){
			swap(a[i],a[n-i+1]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}