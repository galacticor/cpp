#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,a[200];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=100;j++){
		for(int i=1;i<n;i++){
			if(a[i]>a[i+1]){
				swap(a[i],a[i+1]);
				cout<<i<<" "<<i+1<<endl;
			}
		}
	}

	return 0;
}