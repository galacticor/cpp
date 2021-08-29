#include <bits/stdc++.h>
using namespace std;

pair<<int,int>b[100010];

int main(){
	cin>>n>>p>>q>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].first=a[i];
		b[i].second=i;
	}
	sort(b+1,b+n+1);
	if(p>=0 && q>=0 && r>=0){
		x=b[n].first;
		y=x;
		z=x;
	}
	else if(p<0 && q<0 && r<0){
		x=b[1].first;
		y=x;
		z=x;
	}
	else{
		if(p<0 && p<=q && p<=r){
			x=b[1].first;
			if(q<=0){
				y=x;
			}
			else{
				y=b[n].first;
				
			}
			if(r<=0){
				z=x;
			}
			else{
				z=y;
			}
		}
		if(q<0 && q<=p && q<=r){
			y=b[1].first;
			if(p<=0){
				x=y;
			}
			else{
				while(b[tempn].second>b[1].second){
					tempn--;
				}
				x=b[tempn].first;
				
			}
			if(r<=0){
				z=y;
			}
			else{
				z=x;
			}
		}
		if(r<0 && r<=p && r<=q){
			if(p<=0){
				x=b[1].first;
				if(q<=0){
					y=x;
				}
				else{
					while(b[tempn].second>b[1].second){
						tempn--;
					}
					x=b[tempn].first;
					
				}
			}
			
			if(r<=0){
				z=y;
			}
			else{
				z=x;
			}
		}
	}
}