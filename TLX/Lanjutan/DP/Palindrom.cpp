#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int memo[110][110];
string s;

int lps(int x,int y){
	if(x==y){
		return 1;
	}
	if(x>y) return 0;
	else if(memo[x][y]>0){
		return memo[x][y];
	}
	else{
		if(s[x]==s[y]) memo[x][y]=lps(x+1,y-1)+2;
		else memo[x][y]=max(lps(x,y-1),lps(x+1,y));
		return memo[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(memo,0,sizeof(memo));
		cin>>s;
		cout<<lps(0,s.length()-1)<<endl;
	}

	return 0;
}