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
}bird[500];

ll sum,n,m,xalas1,a[1000005],ans;
pll grad,xalas;

// double grad(int a,int b){
// 	return ((bird[a].y-bird[b].y)*1.0)/((bird[a].x-bird[b].x)*1.0);
// }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>bird[i].x>>bird[i].y;
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			if(bird[i].x==bird[j].x){
				if(bird[i].x<=n){
					sum=2;
					for(int k=j+1;k<=m;k++){
						//cout<<i<<" "<<k<<endl;
						if(bird[j].x==bird[k].x){
							sum++;
						}
					}
					a[bird[i].x]=max(a[bird[i].x],sum);
					//v.push_back(bird[i].x);

				}
			}
			else if(bird[i].y==bird[j].y){
				continue;
			}
			else{
				grad.fi=bird[i].y-bird[j].y;
				grad.se=bird[i].x-bird[j].x;
				xalas.fi=bird[i].x*grad.fi - grad.se*bird[i].y;
				xalas.se=grad.fi;
				//cout<<xalas.se<<endl;
				xalas1=xalas.fi/xalas.se;
				if(xalas.fi%xalas.se==0 && xalas1>0 && xalas1<=n){
					sum=2;
					for(int k=j+1;k<=m;k++){
						pll grad1;
						ll temp1,temp2;
						grad1.fi=bird[i].y-bird[k].y;
						grad1.se=bird[i].x-bird[k].x;
						temp1=grad.fi*grad1.se;
						temp2=grad1.fi*grad.se;
						if(temp1==temp2){
						//	cout<<i<<" "<<j<<" "<<k<<endl;
							sum++;
						}
					}
					//cout<<endl;
					a[xalas1]=max(a[xalas1],sum);
				}
			}
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)a[i]=1;
		//cout<<a[i]<<" ";
		ans+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}