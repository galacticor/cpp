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
	double x,y;	
}pi[100005],qi[100005];

int n,ans[100000];

bool haha(point p,point q,point r){
	if(min(p.x,r.x)<=q.x && q.x<=max(p.x,r.x) && 
		min(p.y,r.y)<=q.y && q.y<=max(p.y,r.y)){
		return true;
	}
	return false;
}

int hehe(point p,point q,point r){
	int val=(q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
	if(val==0) return 0;
	if(val>0) return 1;
	if(val<0) return 2;
}

bool hihi(point p1,point q1,point p2,point q2){
	int o1=hehe(p1,q1,p2);
	int o2=hehe(p1,q1,q2);
	int o3=hehe(p2,q2,p1);
	int o4=hehe(p2,q2,q1);

	if(o1!=o2 && o3!=o4){
		return true;
	}
	if(o1==0 && haha(p1,p2,q1)) return true;
	if(o2==0 && haha(p1,q2,q1)) return true;
	if(o3==0 && haha(p2,p1,q2)) return true;
	if(o4==0 && haha(p2,q1,q2)) return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>n && n!=0){
		int k=0;
		bool cek=false;
		for(int i=1;i<=n;i++){
			cin>>pi[i].x>>pi[i].y>>qi[i].x>>qi[i].y;
		}
		// k++;
		// ans[k]=1;
		for(int i=1;i<=n;i++){
			cek =false;
			for(int j=1;j<=k;j++){
				if(hihi(pi[i],qi[i],pi[ans[j]],qi[ans[j]])){
					ans[j]=i;
					cek=true;
					//break;
				}
			}
			if(!cek){
				k++;
				ans[k]=i;
			}
		}
		cout<<"Top sticks: ";
		for(int i=1;i<=k;i++){
			if(i>1) cout<<", ";
			cout<<ans[i];
		}
		cout<<endl;
	}

	return 0;
}