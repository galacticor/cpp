#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

struct name
{
	int b,d,w;
}baju[105];

short int memo[105][505][105][2];
int n,p,q,ans;
string s;

int f(int x,int y,int z,int ada){
	if(y<0){
		return -3e4;
	}
	if(x==0){
		if(z>=q) return 0;
		else return -3e4;
	}
	else if(memo[x][y][z][ada]!=-1){
		return memo[x][y][z][ada];
	}
	else{
		if(baju[x].w!=baju[x-1].w){
			memo[x][y][z][ada]=max(f(x-1,y,z,0),f(x-1,y-baju[x].b,z+((ada)?0:1),0)+baju[x].d);
		}
		else{
			memo[x][y][z][ada]=max(f(x-1,y,z,ada),f(x-1,y-baju[x].b,z+((ada)?0:1),1)+baju[x].d);	
		}
		return memo[x][y][z][ada];
	}
}

bool cmp(name a,name b){
	return a.w<b.w;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin,s);
	cin>>n>>p>>q;
	memset(memo,-1,sizeof(memo));
	for(int i=1;i<=n;i++){
		cin>>baju[i].b>>baju[i].d>>baju[i].w;
	}
	sort(baju+1,baju+n+1,cmp);
	ans=f(n,p,0,0);
	if(ans<0){
		ans=-1;
	}
	cout<<ans<<endl;

	return 0;
}