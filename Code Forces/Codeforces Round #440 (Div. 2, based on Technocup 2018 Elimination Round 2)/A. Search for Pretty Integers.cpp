#include <bits/stdc++.h>
using namespace std;

int n,m,mins,mins1,res,a[100],b[100];

int main(){
	cin>>n>>m;
	mins=100000;
	mins1=100000;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mins=min(a[i],mins);
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
		mins1=min(b[i],mins1);
	}
	if(mins==mins1 && mins==1){
		cout<<mins<<endl;
	}
	else if(mins<mins1){
		cout<<mins<<mins1<<endl;
	}
	else{
		cout<<mins1<<mins<<endl;
	}
	return 0;
}