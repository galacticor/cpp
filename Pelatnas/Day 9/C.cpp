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
const ld phi=acos(-1.0);
const ld eps=1e-9;

struct point{
	ll x,y;
};

struct polygon{
	vector<point>tit;
};

ld ans;	

bool cmp(point a,point b){
	return a.x<b.x || (a.x==b.x && a.y<b.y);
}

ll orien(point p, point q, point r) {
	return (q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);
}

polygon chull(polygon p){
	polygon res;
	int n = p.tit.size(), k = 0;

	vector<point> ch1(2*n), tmp;
	for(int i=0; i<n; i++) {
		tmp.push_back(p.tit[i]);
	}
	sort(tmp.begin(),tmp.end(),cmp);
	for (int i = 0; i<n; i++) {
		while (k>=2 && orien(ch1[k-2],ch1[k-1],tmp[i])<=0) k--;
		ch1[k++]=tmp[i];
	}
	int t=k+1;
	for (int i=n-1; i>0; i--) {
		while (k>=t && orien(ch1[k-2],ch1[k-1],tmp[i-1])<=0) k--;
		ch1[k++]=tmp[i-1];
	}
	ch1.resize(k-1);
	
	for(int i=0; i<ch1.size(); i++) {
		res.tit.push_back(ch1[i]);
	}
	return res;
}

ld area(polygon a) {
	int n=a.tit.size();
	ld ans=0.0;
	int j=n-1;
	for(int i=0; i<n; i++) {
		ans += (a.tit[j].x + a.tit[i].x) * (a.tit[j].y - a.tit[i].y);
		j=i;
	}
	ans/=2;
	if(ans<0) ans*=-1;
	return ans;
}

int n;
polygon axx, ch;

void solve() {
	ld area1=area(axx);
	ld area2=area(ch);
	ans=area2-area1;

	ans=ans*1.0/area2;
	ans*=100;
	
}

point Point(ll x,ll y){
	point ret;
	ret.x=x;
	ret.y=y;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("masuk.txt", "r", stdin);

	cin>>n;
	for(int i=0; i<n; i++) {
		ll x,y;
		cin>>x>>y;
		axx.tit.push_back(Point(x,y));
	}
	ch=chull(axx);
	solve();

	cout<<fixed<<setprecision(4)<<ans<<endl;
	return 0;
}