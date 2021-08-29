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

bool p=false;
int n,m,pre,maks,idx,ans=0;
struct name
{
	int l,r;	
}mon[100005];


bool cmp(name a,name b){
	return a.l<b.l;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>mon[i].l>>mon[i].r;
	}
	sort(mon+1,mon+n+1,cmp);
	pre=1;
	for(int i=1;i<=n;i++){
		if(mon[i].l>pre){
			p=true;
			break;
		}
		else{
			int j=i;
			maks=-1;
			while(mon[j].l<=pre && j<=n){
				if(mon[j].r>maks){
					maks=mon[j].r;
					idx=j;
				}
				j++;
			}
			//cout<<idx<<endl;
			i=j-1;
			pre=maks+1;
			ans++;
		}
	}
	if(pre-1<m)ans=-1;
	if(p){
		ans=-1;
	}
	cout<<ans<<endl;	

	return 0;
}