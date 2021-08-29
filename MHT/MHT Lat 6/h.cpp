#include <bits/stdc++.h>
using namespace std;

int n,m,a[100010],x,y;
bool p;

int main(){
	cin>>n>>m;
	p=true;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		if(a[i]==1 || a[i]==n){
			p=false;
		}
	}
	sort(a+1,a+m+1);
	
	for(int i=3;i<=m;i++){
		x=a[i]-a[i-1];
		y=a[i-1]-a[i-2];
		if(x==1 && y==1){
			p=false;
			break;
		}
	}
	if(p){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
