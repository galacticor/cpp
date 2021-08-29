#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

int ans,t,n,m,a[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>m;
		vector<int> v[1005];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
		}
		ans=0;
		int x=0;
		while(v[x].size()>0){
			//cout<<x<<endl;
			int maks=-1;
			int temp1;
			for(int i=0;i<v[x].size();i++){
				int temp=v[x][i];
				//cout<<temp<<endl;
				if(a[temp]>maks){
					maks=a[temp];
					temp1=temp;
				}
			}
			ans+=maks;
			x=temp1;
			//cout<<ans<<endl;
		}
		cout<<"Case "<<tc<<": "<<ans<<" "<<x<<endl;
	}

	return 0;
}