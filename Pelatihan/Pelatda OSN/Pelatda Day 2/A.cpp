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

int n,m,prefix[110][110],temp,ans;
char a;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>n && n){
		cin>>m;
		ans=0;
		memset(prefix,0,sizeof(prefix));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a;
				prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+int(a-'0');
				//cout<<prefix[i][j]<<" ";
			}
			//cout<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=i;k<=n;k++){
					for(int l=j;l<=m;l++){
						temp=prefix[k][l]-prefix[k][j-1]-prefix[i-1][l]+prefix[i-1][j-1];
						if(temp==(k-i+1)*(l-j+1)){
							ans++;
						}
						//cout<<temp<<endl;
						
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}