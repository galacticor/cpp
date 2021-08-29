#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,a[100010],ans;

bool sorted(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			temp=i;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(!sorted()){
		for(int i=temp;i<=n;i++){
			if(a[i]>a[i+1]){
				swap(a[i+1],a[i]);
				ans++;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}