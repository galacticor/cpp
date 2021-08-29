#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,a[1010],prefix[1010],memo[1010][1010];

int sum(int x,int y){
	return prefix[y]-prefix[x-1];
}

int f(int x,int y){
	if(x==y){
		return a[y];
	}
	else if(memo[x][y]!=0){
		return memo[x][y];
	}
	else{
		memo[x][y]=max(a[x]+sum(x+1,y)-f(x+1,y),a[y]+sum(x,y-1)-f(x,y-1));
		return memo[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		prefix[i]=prefix[i-1]+a[i];
	}
	cout<<f(1,n)<<endl;


	return 0;
}