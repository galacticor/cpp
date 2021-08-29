#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

int l[5005],a[5005],n;
bool p[5005];

void lis(){
	for(int i=1;i<=n;i++){
		l[i]=1;
		if(a[i]<0) p[i]=false;
		else p[i]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(abs(a[i])>abs(a[j]) && l[i]<l[j]+1){
				if(p[j] && a[i]<0){
					l[i]=l[j]+1;
				}
				else if(!p[j] && a[i]>0){
					l[i]=l[j]+1;
				}
			}
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
	lis();
	int ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans,l[i]);
	}
	cout<<ans<<endl;

	return 0;
}