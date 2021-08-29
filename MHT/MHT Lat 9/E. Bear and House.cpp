#include <bits/stdc++.h>
using namespace std;

int lo,hi,mid,ans,xtinggi,xkotak,xalas;
string s;

void tes(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>s;
}

int main(){
	lo=1;
	hi=1000;
	while(lo<=hi){
		mid=(lo+hi)/2;
		tes(mid,0);
		if(s=="YES"){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	xkotak=2*ans;
	lo=1;
	hi=1000;
	while(lo<=hi){
		mid=(lo+hi)/2;
		tes(0,mid);
		if(s=="YES"){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	xtinggi=ans-xkotak;
	lo=1;
	hi=1000;
	while(lo<=hi){
		mid=(lo+hi)/2;
		tes(mid,xkotak);
		if(s=="YES"){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	xalas=2*ans;
	cout<<"! "<<xkotak*xkotak+(xalas*xtinggi)/2<<endl;
	return 0;
}