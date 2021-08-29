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

int n,m,k,temp,ans;
char a[2010][2010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m>>k;
	temp=0;
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='.'){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='.'){
				temp++;
			}
			else{
				ans+=max(0,temp-k+1);
				temp=0;
			}

		}
		ans+=max(0,temp-k+1);
		temp=0;
	}
	temp=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]=='.'){
				temp++;
			}
			else{
				ans+=max(0,temp-k+1);
				temp=0;
			}
		}
		ans+=max(0,temp-k+1);
		temp=0;
	}
	cout<<ans<<endl;
	return 0;
}