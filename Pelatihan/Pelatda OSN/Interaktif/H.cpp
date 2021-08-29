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

int prefixor[1005][1005];

int fun(int x,int y){
	int mas;
	cout<<"< "<<y-x+1;
	for(int i=x;i<=y;i++){
		cout<<" "<<i;
	}
	cout<<endl;
	cin>>mas;
	return mas;
}

void binser(){
	int lo=1,hi,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(cek(lo,mid,hi)){

		}
	}
}

void solve(int x,int y){
	while(!q.empty()){
		int awal=
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>x>>y;
	prefixor[1][n]=cek(1,n);
	binser();

	return 0;
}