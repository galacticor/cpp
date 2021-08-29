#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

int a[100005],b[100005],n,memo[100][100];

int f(int x,int y){
	if(x==0){
		return 0;
	}
	if(memo[x][y]!=-1){
		return memo[x][y];
	}
	else{
		if(y<=a[x]){
			memo[x][y]=f(x-1,y)+1;
		}
		else{
			memo[x][y]=f(x-1,a[x]-b[x]);
		}
		return memo[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	cout<<min(f(n-1,a[n-1]-b[n-1]),f(n,a[n]-b[n]))<<endl;

	return 0;
}