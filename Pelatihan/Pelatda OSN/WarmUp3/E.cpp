#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

int temp,n,m;
char a[60][60];
bool p[60][60];
std::vector<int> v;

void flood(int x,int y){
	if(0<x && 0<y && x<=m && y<=n && !p[x][y] && a[x][y]=='X'){
		a[x][y]='*';
		flood(x-1,y);
		flood(x+1,y);
		flood(x,y-1);
		flood(x,y+1);
	}
}

void flood2(int x,int y){
	if(0<x && 0<y && x<=m && y<=n && !p[x][y] && a[x][y]!='.'){
		p[x][y]=true;
		if(a[x][y]=='X'){
			temp++;
			p[x][y]=false;
			flood(x,y,true);
		}
		flood2(x-1,y);
		flood2(x+1,y);
		flood2(x,y-1);
		flood2(x,y+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=0;
	while(cin>>n>>m && n && m){
		t++;
		v.clear();
		memset(p,0,sizeof(p));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(!p[i][j] && a[i][j]!='.'){
					temp=0;
					flood(i,j);
					v.push_back(temp);
				}
			}
		}
		sort(v.begin(),v.end());
		cout<<"Throw "<<t<<endl;
		for(int i=0;i<v.size();i++){
			cout<<v[i];
			if(i<v.size()-1) cout<<" ";
		}
		cout<<endl<<endl;
	}

	return 0;
}