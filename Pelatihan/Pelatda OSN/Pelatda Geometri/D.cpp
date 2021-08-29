#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
const int MOD=1000000007;

double ans[1005],maks;
int n,r,a[1005],temp;

double hi(int hyp,int alas){
	return sqrt((hyp*hyp-alas*alas)*1.0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		maks=r;
		for(int j=1;j<i;j++){
			temp=abs(a[i]-a[j]);
			if(temp<=2*r){
				maks=max(maks,ans[j]+hi(2*r,temp));
				//cout<<i<<" "<<j<<" "<<maks<<" "<<temp<<endl;
			}
		}
		ans[i]=maks;
	}
	for(int i=1;i<=n;i++){
		if(i>1){
			cout<<" ";
		}
		cout<<fixed<<setprecision(10);
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}