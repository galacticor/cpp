#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int t,n,maks,maks1,a[1010],x[1010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n;
		memset(x,0,sizeof(x));
		maks=-1;
		maks1=-1;
		p=false;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			x[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(x[i]>1){
				if(i>maks){
					maks=i;
				}
				else if(i==maks){
					if(i>maks1){
						maks1=i;
					}
				}
			}
		}
		if(x[maks]>=4) maks1=maks;
		if(maks1<0 || maks<0){
			cout<<maks1*maks<<endl;
		}
		else cout<<"-1"<<endl;
	}

	return 0;
}