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

string sub,s;
int pmax,vmax,ans;

void pantau(int x,int y){
	cout<<"pantau "<<x<<" "<<y<<endl;
	cin>>s;
}

void tembak(int x){
	cout<<"tembak "<<x<<endl;
}

bool cek(int x,int y){
	cout<<"pantau "<<x<<" "<<y<<endl;
	cin>>s;
	if(s=="YA")return true;
	else return false;
}

void binser(){
	int lo=0,hi=pmax,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(cek(lo,mid)){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>sub;
	cin>>pmax>>vmax;
	if(sub[3]=='3'){
		pantau(0,0);
		if(s=="YA"){
			pantau(2,2);
			if(s=="YA"){
				tembak(4);
			}
			else{
				pantau(2,2);
				if(s=="YA"){
					tembak(3);
				}
				else{
					tembak(0);
				}			
			}
		}
		else{
			pantau(3,3);
			if(s=="YA"){
				tembak(5);
			}
			else{
				pantau(3,3);
				if(s=="YA"){
					tembak(4);
				}
				else{
					tembak(1);
				}			
			}
		}
	}
	else{
		binser();
		cout<<"tembak "<<ans<<endl;
	}

	return 0;
}