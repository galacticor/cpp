#include <bits/stdc++.h>
using namespace std;

int m,n,k,batas[100],a[100010],in,l;
bool p,ketemu;

void rec(int x,int y,int z){
	p=true;
	if(z==n){
		if(x>m && y==0){
			for(int i=0;i<=z-2;i++){
				if(a[batas[i]]==a[batas[i]-1]){
					p=false;
				}
			}
			if(p){
				for(int i=0;i<=z-2;i++){
					cout<<a[batas[i]]<<" ";
				}
				cout<<endl;	
				ketemu=true;
				
			}
		}
	}
	else{
		if(y>0 && !ketemu){
			batas[z]=x+l+1;
			rec(x+l+1,y-1,z+1);
		}
		if(!ketemu ){
			batas[z]=x+l;
			rec(x+l,y,z+1);
		}
	}
}

int main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	cin>>n;
	sort(a+1,a+1+m);
	k=m%n;
	l=m/n;
	rec(1,k,0);

	return 0;
}