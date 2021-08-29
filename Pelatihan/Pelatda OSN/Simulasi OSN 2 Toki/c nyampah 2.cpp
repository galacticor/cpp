#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

string s;
ll arr[305][305],n,m,ans=0, arrans[305][305];

void back() {
	ii temp={n,m};
	while(temp.fi!=1 || temp.se!=1) {
		ll x=temp.fi;
		ll y=temp.se;
		arr[x][y]=0;
		if(x==1){
		 	temp={x,y-1};
		 	continue;
		}
		if(y==1){
		 	temp={x-1,y};
		 	continue;
		}
		if(arrans[x-1][y]>=arrans[x][y-1]) {
			temp={x-1,y};
			continue;
		}
		if(arrans[x-1][y]<arrans[x][y-1]) {
			temp={x,y-1};
			continue;
		}
	}
	arr[1][1]=0;
}

int main() {
	cin>>s;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>arr[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(i==1 && j==1) arrans[i][j]=arr[i][j];
			else {
				ll temp;
				if(i==1) temp=arrans[i][j-1];
				if(j==1) temp=arrans[i-1][j];
				if(i!=1 && j!=1) temp=max(arrans[i][j-1], arrans[i-1][j]);
				arrans[i][j]=temp+arr[i][j];
			}
		}
	}
	ans+=arrans[n][m];
	back();
	memset(arrans, 0, sizeof(arrans));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(i==1 && j==1) arrans[i][j]=arr[i][j];
			else {
				ll temp;
				if(i==1) temp=arrans[i][j-1];
				if(j==1) temp=arrans[i-1][j];
				if(i!=1 && j!=1) temp=max(arrans[i][j-1], arrans[i-1][j]);
				arrans[i][j]=temp+arr[i][j];
			}
		}
	}
	ans+=arrans[n][m];
	
	cout<<ans<<endl;

	return 0;
}