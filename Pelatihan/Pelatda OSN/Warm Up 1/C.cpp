#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,lbin,ans,l[100010],t;
vector <int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		ans=0;
		v.clear();
		cin>>n>>lbin;
		for(int i=1;i<=n;i++){
			cin>>l[i];
		}
		sort(l+1,l+n+1);
		int k=1;
		for(int i=n;i>=k;i--){
			if(l[i]+l[k]<=lbin){
				ans++;
				k++;
			}
			else{
				v.push_back(l[i]);
			}
		}
		ans=ans+v.size();
		cout<<ans<<endl;
		cout<<endl;
	}
	return 0;
}