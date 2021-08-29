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

ll ans1,ans,res,a[1005],temp,maks=-1,ans3;
ll m,n,q;

ll cek(ll x){
	ll sum=0;
	for(int i=1;i<=m;i++){
		sum+=(x/a[i] +1);
	}
	//cout<<sum<<endl;
	return sum;
}

void binser(ll x){
	ll lo=1,hi=maks*n,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		//cout<<mid<<endl;
		if(cek(mid)>=x){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

void binser1(ll x){
	ll lo=1,hi=maks*n,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(cek(mid)>=x){
			ans1=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

bool cek3(ll x){
	binser1(x);
	if(ans1>=ans){
		return true;
	}
	else return false;
}

void binser3(ll x,ll y){
	ll lo=x,hi=y,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		//cout<<mid<<endl;
		if(cek3(mid)){
			ans3=mid;
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

	string sub;
	cin>>sub;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		maks=max(a[i],maks);
	}

	cin>>q;
	//cout<<q<<endl;
	int x;
	for(int i=1;i<=q;i++){
		cin>>x;
		if(x<=m){
			cout<<x<<endl;
			continue;
		}
		ans=-1;
		binser(x);
		//cout<<ans<<" ";
		temp=x-cek(ans-1);
		//cout<<temp<<" ";
		res=-1;
		for(int j=1;j<=m;j++){
			if(ans % a[j]==0){
				temp--;
			}
			if(temp==0){
				res=j;
				break;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}