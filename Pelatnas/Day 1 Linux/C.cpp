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

mt19937 rnd(time(0));
int a[30][30],k;
bool udah;
int row,col,r,c,satu,dua;

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);
	cin>>r>>c;
	int cnt=0;
	while(cnt<(r*c)){
		cnt++;
		udah=false;
		cin>>k;
		if(k==1 || k==3){
			for(int i=1;i<=r;i++){
				for(int j=1;j<=c;j++){
					if(a[i][j]==0){
						a[i][j]=k;
						udah=true;
						cout<<i<<" "<<j<<endl;
						break;
					}
				}
				if(udah) break;
			}
		}
		else{
			for(int i=r;i>0;i--){
				for(int j=c;j>0;j--){
					if(a[i][j]==0){
						a[i][j]=k;
						udah=true;
						cout<<i<<" "<<j<<endl;
						break;
					}
				}
				if(udah) break;
			}
		}
	}

	return 0;
}