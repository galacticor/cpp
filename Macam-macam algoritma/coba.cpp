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
const double eps=1e-9;

int a,b,c;

ld calc(ld x){
	return a*x*x+b*x+c;
}

ld binser(){
	ld lo=-1.0*1e9,hi=1.0*1e9,mid;
	while(fabs(lo-hi)>eps){
		mid=(lo+hi)/2;
		cout<<mid<<endl;
		ld tmp1=calc(mid-eps);
		ld tmp2=calc(mid+eps);
		cout<<tmp1<<" "<<tmp2<<endl;
		if(fabs(tmp1-tmp2)>eps){
			return mid;
		}
		if(tmp1>tmp2+eps){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	return lo;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("masuk.txt","r",stdin);

	//ax^2+bx+c=0

	cin>>a>>b>>c;
	cout<<binser()<<endl;

	return 0;
}