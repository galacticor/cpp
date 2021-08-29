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
	ll idx;
	bool st;
}titx[4005],tity[4005];

bool cmpx(point a,point b){
	return a.x<b.x || (a.x==b.x && a.y<b.y);
}

bool cmpy(point a,point b){
	return a.y<b.y || (a.y==b.y && a.x<b.x);
}
bool aktif[4005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// freopen ("masuk.txt","r",stdin);
	ll ans=0,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		titx[i]={x1,y1,i,0};
		titx[n+i]={x2,y2,i,1};
		tity[i]=titx[i];
		tity[n+i]=titx[n+i];
	}

	sort(titx+1,titx+2*n+1,cmpx);
	sort(tity+1,tity+2*n+1,cmpy);
	aktif[titx[1].idx]=true;
	for(int i=2;i<=2*n;i++){
		ll disx=titx[i].x-titx[i-1].x;
		ll disy=0,cury=0,cnt=0;
		//if(disx==0)continue;
		//cout << i << endl;
		for(int j=1;j<=2*n;j++){
			if(!aktif[tity[j].idx])continue;
			if(cnt>0){
				disy+=tity[j].y-cury;
			}
			if(!tity[j].st){
				cnt++;
			}
			else{
				cnt--;
			}
			cury=tity[j].y;
		}
		ans+=(disx*disy);
		if(!titx[i].st) aktif[titx[i].idx]=true;
		else aktif[titx[i].idx]=false;
	}
	cout<<ans<<endl;

	return 0;
}