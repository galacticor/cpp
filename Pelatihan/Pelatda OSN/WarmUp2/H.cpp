#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int ans,m,t,r,w,a[500];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ans=0;
	cin>>m>>t>>r;
	if(t<r){
		cout<<"-1"<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w;
		for(int j=1;j<=r;j++){
			if(i==1){
				a[j]=w-j+t;
			//	v.push_back(w-j);
				ans++;
			}
			else{
				if(a[j]<w){
					if(w-a[j]<t){
						a[j]=w-j+t;
					//	v.push_back(w-j);
						ans++;
					}
					else{
						a[j]=w-j+t;
					//	v.push_back(w-j);
						ans++;
					}
				}
			}
			//cout<<a[j]<<" ";
		}
		sort(a+1,a+r+1);
	//	cout<<endl;
	}
	sort(v.begin(),v.end());
	// for(int i=0;i<v.size();i++){
	// 	cout<<v[i]<<endl;
	// }
	cout<<ans<<endl;
	return 0;
}