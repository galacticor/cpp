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

ll n,m,ans,ans1;

ll mat[10][10];

void init(){
	mat[1][1]=0;
	mat[1][2]=0;
	mat[2][1]=0;
	mat[1][3]=0;
	mat[3][1]=0;
	mat[1][4]=2;
	mat[1][5]=4;
	mat[2][2]=0;
	mat[2][3]=4;
	mat[2][4]=8;
	mat[2][5]=10;
	mat[3][2]=4;
	mat[3][3]=8;
	mat[3][4]=12;
	mat[3][5]=14;
	mat[4][1]=2;
	mat[4][2]=8;
	mat[4][3]=12;
	mat[4][4]=16;
	mat[4][5]=20;
	mat[5][5]=24;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	cin>>n>>m;
	ans+=(n-(n%6)) * m;
	ans+=(m-(m%6)) * (n%6);
	ll x=(m%6),y=(n%6);
	ans+=mat[min(x,y)][max(x,y)];

	ans1+=(n-(n%4)) * m;
	ans1+=(m-(m%4)) * (n%4);
	x=(n%4); y=(m%4);
	ans1+=mat[min(x,y)][max(x,y)];
	cout<<max(ans,ans1)<<endl;
	return 0;
}