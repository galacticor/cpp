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

vi v;
int n,ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	int maks=-1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
		maks=max(maks,x);
	}
	ans=0;
	while((int)v.size()>1){
		int i=0;
		while(i<(int)v.size()){
		// 	cout<<v[i]<<" ";
		// 	for(int j=0;j<v.size();j++){
		// 	cout<<v[j]<<' ';
		// }
		// cout<<ans<<endl;
			if((int)v.size()==1) break;
			if(i==0){
				if(v[i]<=v[i+1]){
					ans+=v[i+1];
					v.erase(v.begin()+i);
				}
				else i++;
			}
			else if(i==(int)v.size()-1){
				if(v[i]<=v[i-1]){
					ans+=v[i-1];
					v.erase(v.begin()+i);
				}
				else i++;
			}
			else{
				if(v[i]<=v[i+1] && v[i]<=v[i-1]){
					ans+=min(v[i+1],v[i-1]);
					v.erase(v.begin()+i);
				}
				else i++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}