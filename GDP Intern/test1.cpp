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

int a,b,arr[1005][1005],index_max,index_min,tmpmax,tmpmin;
int dpmax[1005][1005],dpmin[1005][1005],maks,mins;
int max1[1005][1005],min1[1005][1005];

int ubah(string s){
	int ret = 0;
	for(int i=0;i<(int)s.length();i++){
		ret*=10;
		ret+=int(s[i]-'0');
		
	}
	return ret;
}

int recmax(int x,int y){
	 //cout<<x<<" "<<y<<endl;
	if(x>a){
		return 0;
	}
	if(dpmax[x][y]!=-1){
		return dpmax[x][y];
	}
	else{
		if(arr[x][y]==0) dpmax[x][y]=recmax(x+1,y)+arr[x][y];
		else{
			int tmp1=-1e9,tmp2=-1e9;
			if(y+1<=b && y+1>0){
				tmp1 = recmax(x+1,y+1)+arr[x][y];
			}
			if(y-1<=b && y-1>0){
				tmp2 = recmax(x+1,y-1)+arr[x][y];
			}
			dpmax[x][y]=max(tmp1,tmp2);
		}
		return dpmax[x][y];
	}
}

int recmin(int x,int y){
	 //cout<<x<<" "<<y<<endl;
	if(x>a){
		return 0;
	}
	if(dpmin[x][y]!=-1){
		return dpmin[x][y];
	}
	else{
		if(arr[x][y]==0){
			dpmin[x][y]=recmin(x+1,y)+arr[x][y];
			min1[x][y]=min1[x+1][y];
		}
		else{
			int tmp1=1e9,tmp2=1e9;
			if(y+1<=b && y+1>0){
				tmp1 = recmin(x+1,y+1)+arr[x][y];
			}
			if(y-1<=b && y-1>0){
				tmp2 = recmin(x+1,y-1)+arr[x][y];
			}
			dpmin[x][y]=min(tmp1,tmp2);
		}
		return dpmin[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>a>>b;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			string s;
			cin>>s;
			if(s==".") arr[i][j]=0;
			else arr[i][j]=ubah(s);
		}
	}

	maks=-1e9;
	mins=1e9;

	memset(dpmax,-1,sizeof(dpmax));
	memset(dpmin,-1,sizeof(dpmin));
	
	for(int i=1;i<=b;i++){
		tmpmax=recmax(1,i);
		tmpmin=recmin(1,i);
		// cout<<i<<endl<<tmpmax<<" "<<tmpmin<<endl;
		if(tmpmax>maks){
			index_max=i;
			maks=tmpmax;
		}
		if(tmpmin<mins){
			index_min=i;
			mins=tmpmin;
		}
	}

	cout<<index_max<<" "<<maks<<" "<<3<<endl;
	cout<<index_min<<" "<<mins<<" "<<1<<endl;

	return 0;
}