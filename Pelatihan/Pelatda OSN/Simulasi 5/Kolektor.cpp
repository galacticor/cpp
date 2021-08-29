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

int g[100005],s[100005],p[100005],HH,x,y,z,jmlx=0,jmly=0,jmlz=0;
bool pcek[100005],scek[100005],gcek[100005],fix[100005];
ll ans=0;

priority_queue<pii,vii,greater<pii>> pqx,pqy,pqz;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>HH;
	cin>>x>>y>>z;
	for(int i=1;i<=x+y+z;i++){
		cin>>g[i]>>s[i]>>p[i];
		if(g[i]>=s[i] && g[i]>=p[i]){
			ans+=g[i];
			gcek[i]=true;
			jmlx++;
			pqy.push({g[i]-s[i],i});
			pqz.push({g[i]-p[i],i});
		}
		else{
			if(s[i]>p[i]){
				ans+=s[i];
				scek[i]=true;
				jmly++;
				pqx.push({s[i]-g[i],i});
				pqz.push({s[i]-p[i],i});
			}
			else{
				ans+=p[i];
				pcek[i]=true;
				jmlz++;
				pqy.push({p[i]-s[i],i});
				pqx.push({p[i]-g[i],i});
			}
		}
		//cout<<ans<<endl;
	}
	//cout<<jmlx<<" "<<jmly<<" "<<jmlz<<endl;
	//cout<<x<<" "<<y<<" "<<z<<endl;
	while(!(jmlx==x && jmly==y && jmlz==z)){
		//cout<<jmlx<<" "<<jmly<<" "<<jmlz<<endl;
		while(jmlx<x){
			int val=pqx.top().fi;
			int idx=pqx.top().se;
			pqx.pop();
			//if(!gcek[idx]){
				//gcek[idx]=true;
				if(scek[idx]){
					scek[idx]=false;
					pqz.push({s[idx]-p[idx],idx});
					jmly--;
				}
				else{
					pcek[idx]=false;
					pqy.push({p[idx]-s[idx],idx});
					jmlz--;
				}
				ans-=val;
				jmlx++;
			//}
		}
		while(jmly<y){
			int val=pqy.top().fi;
			int idx=pqy.top().se;
			pqy.pop();
			//if(!scek[idx]){
				//scek[idx]=true;
				if(gcek[idx]){
					gcek[idx]=false;
					pqz.push({g[idx]-p[idx],idx});
					jmlx--;
				}
				else{
					pcek[idx]=false;
					pqx.push({p[idx]-g[idx],idx});
					jmlz--;
				}
				ans-=val;
				jmly++;
			//}
		}
		while(jmlz<z){
			int val=pqz.top().fi;
			int idx=pqz.top().se;
			pqz.pop();
			//if(!pcek[idx]){
				//pcek[idx]=true;
				if(gcek[idx]){
					gcek[idx]=false;
					pqy.push({g[idx]-s[idx],idx});
					jmlx--;
				}
				else{
					scek[idx]=true;
					pqx.push({s[idx]-g[idx],idx});
					jmly--;
				}
				ans-=val;
				jmlz++;
			//}
		}
	}
	cout<<ans<<endl;
	return 0;
}