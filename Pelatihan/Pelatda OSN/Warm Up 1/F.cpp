#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,x,a[1010],ans;
bool p;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=1000;i++){
		p=false;
		for(int j=1;j<=1000;j++){
			if(a[j]>=i){
				ans++;
				p=true;
			}
		}
		if(p){
			ans--;
		}
	}
	cout<<ans<<endl;

	return 0;
}