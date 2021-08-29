#include <bits/stdc++.h>
using namespace std;

struct name
{	
	int s;
	int e;
	int d;
}tamu[100010];

int n,sum,temp;

bool cmp(name a,name b){
	return a.e<b.e || ((a.e==b.e) && (a.s>=b.s));
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tamu[i].s>>tamu[i].d;
		tamu[i].e=tamu[i].s+tamu[i].d;
	}
	sort(tamu+1,tamu+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(tamu[i].s>=temp){
			sum++;
			temp=tamu[i].e;
		}
	}
	cout<<sum<<endl;
	return 0;
}