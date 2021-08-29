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

int prefixa[100005],prefixb[100005],ans,n,k;
char c;

bool cek(int x){
	int tempa,tempb;
	for(int i=0;i<=n-x;i++){
		tempa=prefixa[i+x]-prefixa[i];
		tempb=prefixb[i+x]-prefixb[i];
		if(min(tempb,tempa)<=k){
			return true;
		}
	}
	return false;
}

void binser(){
	int lo=1,hi=n,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
	//	cout<<mid<<endl;
		if(cek(mid)){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>c;
		if(c=='a'){
			a=1; b=0;
		}
		else{
			a=0; b=1;
		}
		prefixa[i]=prefixa[i-1]+a;
		prefixb[i]=prefixb[i-1]+b;
	//	cout<<prefixa[i]<<' '<<prefixb[i]<<endl;
	}
	binser();
	cout<<ans<<endl;
	return 0;
}