#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int memo[1010][1010];
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
	freopen("masuk.txt","r",stdin);

	cin>>s;
	// panggil lps(x,y) mulai index x sampai y
	cout<<lps(0,s.length()-1)<<endl;

	return 0;
}