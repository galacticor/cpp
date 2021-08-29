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

ll st[400005],lz[400005],n,m,q,a,b;

// void build(int l,int r,int pos){
// 	if(l==r){
// 		st[pos]=a[l];
// 		return;
// 	}
// 	int mid=(l+r)/2;
// 	build(l,mid,pos*2);
// 	build(mid+1,r,pos*2+1);
// 	st[pos]=st[pos*2]+st[pos*2+1];
// }

void pushdown(int l,int r,int pos){
	lz[pos]%=2;
	if(lz[pos]==0) return;
	
	st[pos]=(r-l+1)-st[pos];
	if(l!=r){
		lz[pos*2]+=lz[pos];
		lz[pos*2+1]+=lz[pos];
	}
	lz[pos]=0;
}

void update(int l,int r,int x,int y,int val,int pos){
	pushdown(l,r,pos);
	if((x<=l) && (r<=y)){		//full
		lz[pos]+=val;
		pushdown(l,r,pos);
		return;
	}
	if((l>y) || (r<x)){			//no
		return;
	}
	int mid=(l+r)/2;
	update(l,mid,x,y,val,pos*2);
	update(mid+1,r,x,y,val,pos*2+1);
	st[pos]=st[pos*2] + st[pos*2+1];
}

ll get(int l,int r,int x,int y,int pos){
	pushdown(l,r,pos);
	if((x<=l) && (r<=y)){
		return st[pos];
	}
	if((l>y) || (r<x)){
		return 0;
	}
	int mid=(l+r)/2;
	return get(l,mid,x,y,pos*2)+get(mid+1,r,x,y,pos*2+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	//head=0;
	for(int i=1;i<=m;i++){
		cin>>q>>a>>b;
		a++;
		b++;
		if(q==1){
			cout<<get(1,n,a,b,1)<<endl;
		}
		else{
			update(1,n,a,b,1,1);
		}
	}

	return 0;
}