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
	ll x,y;
}titik[100005];
point p0;
int n;
vector <point> v;
stack <point> st;
ld ans;

point tmp,ret;

int val;
int orien(point p,point q,point r){
	val=(r.x-q.x)*(q.y-p.y)-(r.y-q.y)*(q.x-p.x);

	if(val==0)return 0;
	else if(val>0)return 1; //cw
	else return 2; 	//ccw
}

ld dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void swap(point &p1,point &p2){
	tmp=p1;
	p1=p2;
	p2=tmp;
}

bool cmp(point p1,point p2){
	return p1.x<p2.x || (p1.x==p2.x && p1.y<p2.y);
}

bool cmp1(point p1,point p2){
	return p1.x<p2.x || (p1.x==p2.x && p1.y>p2.y);
}

void polygonkeliling(){
	ans=0.0;
	int j=(int)v.size()-1;
	for(int i=0;i<(int)v.size();i++){
		ans+=dist(v[i],v[j])*1.0;
		j=i;
	}
}

point prevpo(){
	tmp=st.top();
	st.pop();
	ret=st.top();
	st.push(tmp);
	return ret;
}

void solve(){
	point p,nx,c;
	int o;

	p=titik[1];
	c=titik[2];
	st.push(p);
	st.push(c);
	for(int i=3;i<=n;i++){
		nx=titik[i];
		p=prevpo();
		c=st.top();
		o=orien(p,c,nx);
		// cout<<p.x<<" "<<p.y<<" ";
		// cout<<c.x<<" "<<c.y<<endl;
		if(o==2){
			st.pop();
			while(o==2 || (int)st.size()<2){
				p=prevpo();
				c=st.top();
				o=orien(p,c,nx);
				if(o==2){
					st.pop();
				}
			}
		}
		st.push(nx);
	}
	p=titik[n];
	c=titik[n-1];
	st.push(c);
	for(int i=n-2;i>0;i--){
		nx=titik[i];
		p=prevpo();
		c=st.top();
		o=orien(p,c,nx);
		// cout<<p.x<<" "<<p.y<<" ";
		// cout<<c.x<<" "<<c.y<<endl;
		// cout<<nx.x<<" "<<nx.y<<endl;
		// cout<<o<<endl;
		if(o==2){
			st.pop();
			while(o==2 || (int)st.size()<2){
				p=prevpo();
				c=st.top();
				o=orien(p,c,nx);
				if(o==2){
					st.pop();
				}
			}
		}
		st.push(nx);
	}
	while(!st.empty()){
		v.push_back(st.top());
		st.pop();
	}
	
	polygonkeliling();
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

	// for(int i=0;i<(int)v.size();i++){
	// 	cout<<v[i].x<<" "<<v[i].y<<endl;
	// }
	
	cout<<fixed<<setprecision(6);
	cout<<ans<<endl;
	// cout<<orien(titik[4],titik[5],titik[6])<<endl;

	return 0;
}