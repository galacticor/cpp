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

int n,t,r,bip,ans1,ans2;
string gr,s;
bool p,cek;

void interact(int x){
	cout<<x<<endl;
	cin>>gr;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>s;
	cin>>n>>t>>r;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(n+1)/2;j++){
			interact(i);
			if(gr=="BIP"){
				ans1=i;
				ans2=i-1;
				bip++;
				p=true;
				cek=true;
				break;
			}
		}
		if(cek) break;
	}
	if(p){
		while(bip<n){
			if(ans1>0){
				interact(ans1);
				if(gr=="BIP"){
					bip++;
				}
			}
			if(bip>=n) break;
			if(ans2>0){
				interact(ans2);
				if(gr=="BIP"){
					bip++;
				}
			}
			if(bip>=n) break;
		}
	}
	else{
		while(bip<n){
			interact(n);
			if(gr=="BIP"){
				bip++;
			}
		}
	}
	return 0;
}