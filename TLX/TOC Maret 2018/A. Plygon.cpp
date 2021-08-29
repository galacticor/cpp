#include <bits/stdc++.h>
using namespace std;

int a[5000],b[5000],x,y,n;
bool p;

int main(){
	p=true;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[1001+x]++;
		b[1001+y]++;
	}

	for(int i=1;i<=2001;i++){
		if(a[i]%2!=0 || b[i]%2!=0){
			p=false;
		}
	}
	if(p){
		cout<<"YA"<<endl;
	}
	else{
		cout<<"TIDAK"<<endl;
	}

}