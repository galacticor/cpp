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
const ld eps=1e-9;

mt19937 rnd(time(0));
int n,masuk,a[100005];
bool vis[100005];

void tanya(int x){
	cout<<"? "<<x<<endl;
	int masuk;
	cin>>masuk;
	a[x]=masuk;
}

bool cek(int x,int y){
	return x==y;
}

bool move(int p,int q,int r,int s){
	return (p<q) ^ (r<s);
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);cout.tie(NULL);
	// freopen("masuk.txt","r",stdin);

	cin>>n;
	if(n%4){
		cout<<"! -1"<<endl;
		return 0;
	}
	
	tanya(1); tanya(1+n/2); 
	tanya(n/2); tanya(n);
	if(cek(a[1],a[1+n/2])){
		cout<<"! "<<1<<endl;
		return 0;
	}
	if(cek(a[n/2],a[n])){
		cout<<"! "<<n/2<<endl;
		return 0;
	}
	int lo=1,hi=n,mid=(lo+hi)/2;
	while(lo<=hi){
		mid=(lo+hi)/2;
		// tanya(lo); tanya(lo+n/2);
		tanya(mid); tanya(mid+n/2);
		// if(cek(a[lo],a[lo+n/2])){
		// 	cout<<"! "<<lo<<endl;
		// 	return 0;
		// }
		if(cek(a[mid],a[mid+n/2])){
			cout<<"! "<<mid<<endl;
			return 0;
		}
		if(move(a[lo],a[lo+n/2],a[mid],a[mid+n/2])){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	cout<<"! -1"<<endl;

	return 0;
}