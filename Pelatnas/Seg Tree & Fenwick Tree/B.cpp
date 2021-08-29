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

int st[120005],n,co,q,qu,a[100005],t;

void build(int l,int r,int pos){
	if(l==r){
		st[pos]=a[l];
		st2[pos]=st[pos];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,pos*2);
	build(mid+1,r,pos*2+1);
	st[pos]=st[pos*2]+st[pos*2+1];
	st2[pos]=min(st2[pos*2],st2[pos*2+1]);
}

void update(int l,int r,int x,int pos,int val){
	st[pos]+=val;
	int mid=(l+r)/2;
	if(l==r)return;
	if(x<=mid){
		update(l,mid,x,pos*2,val);
	}
	else{
		update(mid+1,r,x,pos*2+1,val);
	}
	st[pos]=st[pos*2]+st[pos*2+1];

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin>>n){
		co++;
		char c;
		for(int i=1;i<=n;i++){
			cin>>c;
			if(c=='('){
				a[i]=-1;
			}
			else{
				a[i]=1;
			}
		}
		build(1,n,1);
		cin>>m;
		while(m--){
			//cout<<t++<<endl;
			//cout<<qu<<endl;
			cin>>qu;
			if(qu==0){
				co++;
				cout<<"TEST "<<co<<":"<<endl;
				if(st[1]!=0)cout<<"NO"<<endl;
				else cout<<"YES"<<endl;
			}
			else {
				if(a[qu]==-1){
					update(1,n,qu,1,1);
				}
				else{
					update(1,n,qu,1,-1);
				}
			}
		}
	}


	return 0;
}