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

int a[1000005],n,k,sumk,x;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sumk=0;
	cin>>n>>k;
	bool p=false;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==k) sumk++;
		else if(a[x]-sumk>=0) a[x]++;
	}
	for(int i=1;i<=1000000;i++){
		if(a[i]>=sumk && i!=k){
			cout<<i<<endl;
			p=true;
			break;
		}
	}
	if(!p) cout<<"-1"<<endl;
	return 0;
}