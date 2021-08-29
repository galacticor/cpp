#include <bits/stdc++.h>
using namespace std;

pair<int,int>lvl[100010];
int s,n,x,y;
bool p;

int main(){
	cin>>s>>n;
	p=true;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		lvl[i].first=x;
		lvl[i].second=y;
	}
	sort(lvl+1,lvl+n+1);
	for(int i=1;i<=n;i++){
		if(s>lvl[i].first){
			s=s+lvl[i].second;
		}
		else{
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
