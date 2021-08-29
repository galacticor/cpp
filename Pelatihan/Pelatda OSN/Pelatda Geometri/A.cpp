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
const double phi=acos(-1.0);

struct point
{
	int x,y;	
}pi[105],qi[105];

int n,t,ans;
bool c[105];

bool onsegment(point p,point q,point r){
	if(min(p.x,r.x)<=q.x && q.x<=max(p.x,r.x) && 
		min(p.y,r.y)<=q.y && q.y<=max(p.y,r.y)){
		return true;
	}
	return false;
}

int orien(point p,point q,point r){
	int val=(q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
	if(val==0) return 0;
	if(val>0) return 1; //ccw
	if(val<0) return 2; //cw
}

bool inters(point p1,point q1,point p2,point q2){
	int o1=orien(p1,q1,p2);
	int o2=orien(p1,q1,q2);
	int o3=orien(p2,q2,p1);
	int o4=orien(p2,q2,q1);

	if(o1!=o2 && o3!=o4){
		return true;
	}
	if(o1==0 && onsegment(p1,p2,q1)) return true;
	if(o2==0 && onsegment(p1,q2,q1)) return true;
	if(o3==0 && onsegment(p2,p1,q2)) return true;
	if(o4==0 && onsegment(p2,q1,q2)) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		cin>>n;
		//cout<<t<<endl;
		for(int i=1;i<=n;i++){
			cin>>pi[i].x>>pi[i].y>>qi[i].x>>qi[i].y;
		}
		memset(c,false,sizeof(c));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(hihi(pi[i],qi[i],pi[j],qi[j])){
					c[i]=true;
					c[j]=true;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!c[i]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}