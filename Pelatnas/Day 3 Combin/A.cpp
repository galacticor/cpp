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

int sum,a[100005],n,b,udah[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>b>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		udah[i]=-1;
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		sum%=b;
		if(udah[sum]==-1){
			udah[sum]=i;
		}
		else{
			cout<<udah[sum]+1;
			for(int j=udah[sum]+2;j<=i;j++){
				cout<<" "<<j;
			}
			cout<<endl;
			return 0;
		}
	}

	return 0;
}