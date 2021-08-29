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

vector<ll> prima;
ll a[30],t,tc,n,jaw;
string res;
bool gak;

void init(){
	prima.push_back(2);
	prima.push_back(3);
	for(ll i=4;i<=1e6;i++){
		gak=false;
		for(int j=0;j<(int)prima.size();j++){
			if(prima[j]*prima[j]>i) break;
			if(i%prima[j]==0){
				gak=true;
				break;
			}
		}
		if(!gak) prima.push_back(i);
	}
}

ll depan(ll x){
	ll ans;
	ll tmp=(x-1)%12;
	tmp++;
	if(tmp==1 or tmp==6 or tmp==7 or tmp==12) {
		res="WS";
	}
	if(tmp==2 or tmp==5 or tmp==8 or tmp==11) {
		res="MS";
	}
	if(tmp==3 or tmp==4 or tmp==9 or tmp==10) {
		res="AS";
	}
	
	ll temp=(x-1)/12;
	ans=(temp*12)+(13-tmp);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>tc;
	init();
	for(int t=1;t<=tc;t++){
		cin>>n;
		jaw=1e18;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			ll tmp=depan(a[i]);
			gak=false;
			for(int j=0;j<(int)prima.size();j++){
				if(prima[j]*prima[j]>tmp) break;
				if(tmp%prima[j]==0){
					gak=true;
					break;
				}
			}
			if(!gak){
				jaw=min(jaw,a[i]);
			}
		}
		cout<<"Kasus #"<<t<<": "<<endl;
		if(jaw>1e12){
			cout<<"Makanya Jangan Aneh - Aneh"<<endl;	
		}
		else cout<<depan(jaw)<<" "<<res<<endl;
		if(t<tc) cout<<endl;
	}

	return 0;
}