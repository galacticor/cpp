#include <bits/stdc++.h>
using namespace std;

int r,c,x1,x;
char a[500][500];
bool p,q,o;

void tetris(){
	for(int i=1;i<=r;i++){
		x1=0;
		for(int j=1;j<=c;j++){
			if(a[i][j]=='1'){
				x1++;
			}			
		}
		if(x1==c){
			p=true;
			for(int k=1;k<=c;k++){
				a[i][k]='0';
			}
			if(i==r){
				x=i;
			}
			else{
				x=i+1;
			}
		}
	}
}

void tetris1(){
	q=true;
	while(q){
		q=false;
		for(int i=2;i<=x;i++){
			for(int j=1;j<=c;j++){
				int b=i;
				while(b<=r && a[b][j]!='1'){
					if(a[b-1][j]!='0'){
						q=true;
						swap(a[b][j],a[b-1][j]);
					}
					b++;
				}
			}
		}
		
	}
	
}

int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		x1=0;
		for(int j=1;j<=c;j++){
			cin>>a[i][j];
			//if(a[i][j]=='1'){
			//	x1++;
			//}
		}
		//if(x1==c){
		//	p=true;
		//	for(int k=1;k<=c;k++){
		//		a[i][k]='0';
		//	}
		//	if(i==r){
		//		x=i;
		//	}
		//	else{
		//		x=i+1;
		//	}
		//}
	}
	p=true;
	while(p){
		p=false;
		tetris();
		if(p){
			tetris1();	
		}
	}


	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}