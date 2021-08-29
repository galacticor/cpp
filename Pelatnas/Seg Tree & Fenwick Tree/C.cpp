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

struct seg
{
	ll ki,ka,tengah;
};

seg st[200005];
ll psum[50005],n,m,xi,yi,a[50005];

ll val(int l,int r){
	return psum[r]-psum[l-1];
}

void build(int l,int r,int pos){
	if(l==r){
		st[pos].ki=a[l];
		st[pos].tengah=st[pos].ki;
		st[pos].ka=st[pos].ki;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
	
	st[pos].ki=max(st[pos*2].ki,val(l,mid)+st[pos*2+1].ki);
	st[pos].ka=max(st[pos*2+1].ka,val(mid+1,r)+st[pos*2].ka);
	st[pos].tengah=max(st[pos*2].ka+st[pos*2+1].ki,max(st[pos*2].tengah,st[pos*2+1].tengah));

}

// void update(int l,int r,int x,int val,int pos){
// 	st[pos]+=val;
// 	if(l==r) return;
// 	int mid=(l+r)/2;
// 	if(x<=mid){
// 		update(l,mid,x,val,pos*2);
// 	}
// 	else{
// 		udate(mid+1,r,x,val,pos*2+1);
// 	}	
// }

seg get(int l,int r,int x,int y,int pos){
	int mid=(l+r)/2;
	seg ret;
	if(x==l && r==y){
		return st[pos];
	}
	else if(y<=mid){
		return get(l,mid,x,y,pos*2);
	}
	else if(x>mid){
		return get(mid+1,r,x,y,pos*2+1);
	}
	seg kiri=get(l,mid,x,mid,pos*2);
	seg kanan=get(mid+1,r,mid+1,y,pos*2+1);

	ret.ki=max(kiri.ki,val(l,mid)+kanan.ki);
	ret.ka=max(kanan.ka,val(mid+1,r)+kiri.ka);
	ret.tengah=max(kiri.tengah,max(kanan.tengah,kiri.ka+kanan.ki));
	return ret;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	psum[0]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		psum[i]=psum[i-1]+a[i];
	}
	build(1,n,1);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>xi>>yi;
		cout<<get(1,n,xi,yi,1).tengah<<endl;
	}

	return 0;
}