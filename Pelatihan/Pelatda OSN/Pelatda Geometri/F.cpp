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

int t,n,maks,sz;
double ans;

double res(int p1,int q1,int p2,int q2){
	int alas=abs(p2-p1);
	int tinggi=abs(q2-q1);
	return sqrt((alas*alas+tinggi*tinggi)*1.0);
}

vii v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		v.clear();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			v.push_back({x,y});
		}
		sort(v.begin(),v.end());
		sz=(int)v.size();
		ans+=res(v[sz-1].fi,v[sz-1].se,v[sz-2].fi,v[sz-2].se);
		for(int i=sz-2;i>0;i--){
			if(v[i].se<v[i-1].se){
				maks=-1;
				for(int j=i+1;j<sz;j++){
					maks=max(maks,v[j].se);
				}
				ans+=res(v[i-1].fi,v[i-1].se,v[i].fi,maks);
			}
		}
		cout<<fixed<<setprecision(2);
		cout<<ans<<endl;
	}

	return 0;
}