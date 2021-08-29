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

int n,t,r,ans,temp1,temp2,bip=0;
string s,gr;
vi v,temp;

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
	for(int i=1;i<=n/2;i++){
		v.push_back(i);
	}
	for(int i=n/2;i>0;i--){
		v.push_back(i);
	}
	for(int i=n/2+1;i<=n;i++){
		v.push_back(i);
	}
	for(int i=n;i>n/2;i--){
		v.push_back(i);
	}
	for(int i=1;i<=n/2;i++){
		v.push_back(i);
	}
	for(int i=n/2;i>0;i--){
		v.push_back(i);
	}
	for(int i=n/2+1;i<=n;i++){
		v.push_back(i);
	}
	for(int i=n;i>n/2;i--){
		v.push_back(i);
	}
	for(int i=0;i<(int)v.size();i++){
		interact(v[i]);
		if(gr=="BIP"){
			bip++;
			temp.push_back(i);
		}
		if(bip>=2){
			break;
		}
	}
	for(int i=0;i<n;i++){
		temp1=temp[0];
		temp2=temp[1];
		if(v[temp1-i]==v[temp2-i]){
			ans=v[temp1-i];
			break;
		}
	}
	while(bip<n){
		interact(ans);
		if(gr=="BIP"){
			bip++;
		}
	}

	return 0;
}