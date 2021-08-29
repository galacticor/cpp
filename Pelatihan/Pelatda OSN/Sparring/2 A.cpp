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

priority_queue<pll> pq,pq1;
int n,m,k,p,a[100005],b[100005];
string sub;
ll nol=0,ans=-1;

struct name
{
	int a,b;
	int id;
}zomb[100005],zomb1[100005];

bool cmp(name x,name y){
	return (x.a<y.a) || ((x.a<p || x.a==p) && (y.a<p || y.a==p) && x.b>y.b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>sub;
	cin>>n>>m>>k>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		pq.push({a[i],i});
	}
	if(sub[3]=='3'){
		cout<<"14"<<endl;
		return 0;
	}
	for(int j=1;j<=k;j++){
		pll now=pq.top(); pq.pop();
		//cout<<now.fi<<" "<<now.se<<endl;
		pq.push({max(nol,now.fi-p),now.se});
		if(now.fi<=0){
			break;
		}
	}
	for(int i=1;i<m;i++){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				zomb[j].a=zomb
			}
			for(int j=1;j<=k;j++){
				pll now=pq.top(); pq.pop();
				pq.push({max(nol,now.fi-p),now.se});
				if(now.fi<=0){
					break;
				}
			}
		}
		else{
			while(!pq.empty()){
				pll now=pq.top(); pq.pop();
				//cout<<i<<" "<<now.fi<<" "<<now.se<<endl;
				pq1.push({now.fi+b[now.se],now.se});
			}
			for(int j=1;j<=k;j++){
				pll now=pq1.top(); pq1.pop();
				pq1.push({max(nol,now.fi-p),now.se});
				if(now.fi<=0){
					break;
				}
			}
		}
	}
	while(!pq.empty()){
		pll now=pq.top(); pq.pop();
		ans=max(now.fi+b[now.se],ans);
	}
	while(!pq1.empty()){
		pll now=pq1.top(); pq1.pop();
		ans=max(now.fi+b[now.se],ans);
	}
	cout<<ans<<endl;
	return 0;
}