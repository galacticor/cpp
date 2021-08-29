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

struct point
{
	ll x,y;
}tit[1005],ps;

struct segment
{
	point st,fn;
}sg[1005];

ll n;

int orien(point p,point q,point r){
	int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
	if(val==0) return 0;
	if(val>0) return 1; //CW
	return 2; //CCW
}



ld sqdis(point a,point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool tumpul(point p,point q,point r){
	ll xi,yi,xii,yii;
	xi=p.x-q.x;
	yi=p.y-q.y;
	xii=r.x-q.x;
	yii=r.y-q.y;
	if((xi*xii + yi*yii)<(ll)0){
		return true;
	}
	xi=p.x-r.x;
	yi=p.y-r.y;
	xii=q.x-r.x;
	yii=q.y-r.y;
	if((xi*xii + yi*yii)<(ll)0){
		return true;
	}
	return false;
}

ld jarak(point p,point q,point r){
	ld val=(p.x-q.x)*(r.y-q.y)-(p.y-q.y)*(r.x-q.x);
	val*=1.0;
	val/=(sqrt(1.0*sqdis(p,q))*sqrt(1.0*sqdis(r,q)));
	return sqrt(1.0*sqdis(p,q))*val*1.0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n>>ps.x>>ps.y;
	for(int i=1;i<=n;i++){
		cin>>tit[i].x>>tit[i].y;
		if(i>1){
			sg[i-1].st=tit[i-1];
			sg[i-1].fn=tit[i];
		}
	}
	tit[n+1]=tit[1];
	sg[n].st=tit[n];
	sg[n].fn=tit[n+1];

	ld mins=2e18,maks=-1;
	for(int i=1;i<=n;i++){
		maks=max(maks,sqdis(ps,tit[i]));
		mins=min(mins,sqdis(ps,tit[i]));
	}
	ld mins1=2e18;
	ld ans;
		for(int i=1;i<=n;i++){
			if(!tumpul(ps,tit[i],tit[i+1])){
				if(mins1-eps>abs(jarak(ps,tit[i],tit[i+1])))
					mins1=abs(jarak(ps,tit[i],tit[i+1]));
			}
		}
		if(sqrt(1.0*mins)<mins1-eps){
			mins1=sqrt(1.0*mins);
		}
		//cout<<mins1<<" "<<sqrt(1.0*maks)<<endl;
		ans=(phi*1.0*maks)-(phi*1.0*mins1*mins1);
	cout<<fixed<<setprecision(9);
	cout<<ans<<endl;
	return 0;
}