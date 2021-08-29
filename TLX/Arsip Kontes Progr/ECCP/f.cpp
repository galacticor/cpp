#include <bits/stdc++.h>
using namespace std;

struct name
{
	int harga;
	int quality;
}a[100010];

int maks,n;

bool cmp(name a,name b){
	return a.harga<b.harga;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool p=false;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].harga;
		cin>>a[i].quality;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<n;i++){
		if(a[i].quality>=a[i+1].quality){
			p=true;
		}
	}
	if(!p){
		cout<<"Poor Alex"<<endl;
	}
	else{
		cout<<"Happy Alex"<<endl;
	}
	return 0;
}