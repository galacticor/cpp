#include <bits/stdc++.h>
using namespace std;

long long k;
int maks,n,a[1010],res,win,x,y;


int main(){
	cin>>n>>k;
	y=1;
	maks=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maks=max(maks,a[i]);
	}
	if(k>=n){
		res=maks;
	}
	else{
		win=a[1];
		for(int i=2;i<=10*n;i++){
			if(x==k){
				break;
			}
			else{
				if(win>a[i]){
					a[n+y]=a[i];
					y++;
					x++;
				}
				else{
					x=0;
					a[n+y]=win;
					win=a[i];
					x++;
					y++;
				}	
			}
			
		}
		res=win;
	}
	cout<<res<<endl;
}