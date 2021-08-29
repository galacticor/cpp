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
const int phi=acos(-1.0);

struct point
{
	ll x,y;
};

ll n,ans,sum;
point a[2005];
vii grad;
map<pii,int> tot;

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

bool cmp(point p,point q){
	return p.x<q.x || (p.x==q.x && p.y<q.y);
}

int orien(point p,point q,point r){
	int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(val==0) return 0;
	if(val>0) return 1;
	return 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=n;i++){
		tot.clear();
		for(int j=i+1;j<=n;j++){
			pii tmp; int fpb;
			tmp.fi=a[i].y-a[j].y;
			tmp.se=a[i].x-a[j].x;
			 fpb=gcd(tmp.fi,tmp.se);
			tmp.fi/=fpb;
			tmp.se/=fpb;
			tot[tmp]++;
		}
		map<pii,int>::iterator it;
		for(it=tot.begin();it!=tot.end();++it){
			ll tmp=it->se;
			sum+=(tmp*(tmp-1)/2);
		}
	}
	
	ans=n*(n-1)*(n-2)/6;
	ans-=sum;
	cout<<ans<<endl;
	return 0;
}