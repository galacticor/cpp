#include <bits/stdc++.h>
using namespace std;

int n,k,y,x,res;

int main(){
	cin>>n>>k;
	y=240-k;
	for(int i=2;i<=n+1;i++){
		x=5*i*(i-1)/2;
		if(x<=y){
			res=i-1;
		}
	}
	cout<<res<<endl;
	return 0;
}


