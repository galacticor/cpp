#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int a[5005],ans,n;

int f(int l,int r,int h){
	int mins=1e9+1,ans=0;
	for(int i=l;i<=r;i++){
		mins=min(mins,a[i]);
	}
	if(l>r){
		
	}
	ans+=mins-h;
	int ki=5001, ka=-1;
	for(int i=l;i<=r;i++){
		if(a[i]>mins){
			ki=i;
			while(i<=r && a[i]>mins){
				i++;
			}
			ka=i-1;
			ans+=f(ki,ka,mins);
			ki=5001;
			ka=-1;
		}
	}
	return min(ans,r-l+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<f(1,n,0)<<endl;
	return 0;
}