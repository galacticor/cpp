#include <bits/stdc++.h>
using namespace std;

int t,n,m;
string tes;
bool p;

struct product{
	string id;
	int s1;
	int s2;
	int s3;
} pst[1010];

bool cmp(product a, product b){
	return a.s3>b.s3 || ((a.s3==b.s3)&&(a.s2>b.s2)) || ((a.s3==b.s3)&&(a.s2==b.s2)&&(a.s1>b.s1));
}

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		cin>>tes;
		p=false;
		for(int j=1;j<=n;j++){
			cin>>pst[j].id>>pst[j].s1>>pst[j].s2>>pst[j].s3;
		}
		sort(pst+1,pst+n+1,cmp);
		for(int j=1;j<=m;j++){
			if(pst[j].id==tes){
				p=true;
			}
		}
		if(p){
			cout<<"YA"<<endl;
		}
		else{
			cout<<"TIDAK"<<endl;
		}
	}
	return 0;
}