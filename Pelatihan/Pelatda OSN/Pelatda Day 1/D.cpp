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

int n,m,x,y;
ll k,a[110][110],temp,q,r,maks,mins,t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>k>>x>>y;
	temp=k;
	bool p=false;
	maks=-1;
	mins=2e18;
	if(n==1){
		t=temp/(n*m);
		temp-=t*n*m;
		for(int i=1;i<=m;i++){
			a[1][i]+=t;
			if(temp>0){
				a[1][i]++;
				temp--;
			}
			maks=max(maks,a[1][i]);
			mins=min(mins,a[1][i]);
		}
		cout<<maks<<" ";
		cout<<mins<<" ";
		cout<<a[x][y]<<endl;
		return 0;
	}
	if(temp>=n*m+(n-2)*m){
		q=temp/(n*m+(n-2)*m);
		temp-=q*(n*m+(n-2)*m);
	}
	if(temp>=(n-1)*m){
		temp-=((n-1)*m);
		r++;
		p=true;
	}
	if(p){
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++){
				if(i<n){
					a[i][j]++;
				}
				if(i==n || i==1){
					a[i][j]+=q;
				}
				else{
					a[i][j]+=2*q;
				}
				if(temp>0){
					a[i][j]++;
					temp--;
				}
				maks=max(maks,a[i][j]);
				mins=min(mins,a[i][j]);
			//	cout<<a[i][j]<<" ";
			}
			//cout<<endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i==n || i==1){
					a[i][j]+=q;
				}
				else{
					a[i][j]+=2*q;
				}
				if(temp>0){
					a[i][j]++;
					temp--;
				}
				maks=max(maks,a[i][j]);
				mins=min(mins,a[i][j]);
			}
		}
	}
	//cout<<x<<' '<<y<<endl;
	cout<<maks<<" ";
	cout<<mins<<" ";
	cout<<a[x][y]<<endl;
	return 0;
}