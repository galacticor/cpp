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

ll prefix[200005],a,n,s,ans;

bool cek(int x){
	int temp;
	for(int i=0;i<=n-x;i++){
		if(prefix[i+x]-prefix[i]>=s){
			return true;
		}
	}
	return false;
}

void binser(){
	int lo=1,hi=n,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(cek(mid)){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>n>>s){
		memset(prefix,0,sizeof(prefix));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a;
			prefix[i]=prefix[i-1]+a;
		}
		binser();
		cout<<ans<<endl;	
	}
	return 0;
}