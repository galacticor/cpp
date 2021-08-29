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

int n,q,ax,ans,a[100005];

int lo,hi,mid;
void binser(int x){
	lo=1;hi=n;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(a[mid]==x){
			ans=mid;
			break;
		}
		else if(a[mid]<x){
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
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		cin>>ax;
		ans=-1;
		binser(ax);
		if(ans!=-1){
			cout<<"ada"<<endl;
		}
		else{
			cout<<"tidak ada"<<endl;
		}
	}


	return 0;
}