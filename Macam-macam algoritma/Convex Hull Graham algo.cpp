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

struct point
{
	int x,y;
}titik[100005];
point p0;
int n;
vector <point> v;
ld ans;

point tmp,ret;

int val;
int orien(point p,point q,point r){
	val=(r.x-q.x)*(q.y-p.y)-(r.y-q.y)*(q.x-p.x);

	if(val==0)return 0;
	else if(val>0)return 1; //cw
	else return 2; 	//ccw
}

bool cmp(point p1,point p2){
	return p1.x<p2.x || (p1.x==p2.x && p1.y<p2.y);
}

void solve(){
	point p,nx,c;
	int o;
	p=titik[1];
	c=titik[2];
	v.push_back(p);
	for(int i=3;i<=n;i++){
		nx=titik[i];
		o=orien(p,c,nx);
		if(o==1){
			v.push_back(c);
			p=c;
			c=nx;
		}
		else{
			c=nx;
		}
	}
	v.push_back(nx);
	p=titik[1];
	c=titik[2];
	for(int i=3;i<=n;i++){
		nx=titik[i];
		o=orien(p,c,nx);
		if(o==2){
			v.push_back(c);
			p=c;
			c=nx;
		}
		else{
			c=nx;
		}
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>titik[i].x>>titik[i].y;
	}
	sort(titik+1,titik+n+1,cmp);
	solve();

	for(int i=0;i<(int)v.size();i++){
		cout<<v[i].x<<" "<<v[i].y<<endl;
	}
	
	return 0;
}