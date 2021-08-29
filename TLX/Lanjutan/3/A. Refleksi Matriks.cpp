#include <bits/stdc++.h>
using namespace std;

int p,r,q,s,a[10010][10010],b[10010][10010];

bool identik(){
	for(int i=1;i<=p;i++){
		for(int j=1;j<=q;j++){
			if(a[i][j]!=b[i][j]){
				return false;
			}
		}
	}
	return true;
}

bool vertikal(){
	for(int i=1;i<=p;i++){
		for(int j=1;j<=q;j++){
			if(a[i][j]!=b[i][q-j+1]){
				return false;
			}
		}
	}
	return true;
}

bool horizontal(){
	for(int i=1;i<=p;i++){
		for(int j=1;j<=q;j++){
			if(a[i][j]!=b[p-i+1][j]){
				return false;
			}
		}
	}
	return true;
}

bool kanan(){
	for(int i=1;i<=p;i++){
		for(int j=1;j<=q;j++){
			if(a[i][j]!=b[j][i]){
				return false;
			}
		}
	}
	return true;
}

bool kiri(){
	for(int i=1;i<=p;i++){
		for(int j=1;j<=q;j++){
			if(a[i][j]!=b[q-j+1][p-i+1]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	cin>>p>>q;
	for(int i=1;i<=p;i++){
		for(int j=1;j<=q;j++){
			cin>>a[i][j];
		}
	}
	cin>>r>>s;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=s;j++){
			cin>>b[i][j];
		}
	}
	if(identik()){
		cout<<"identik"<<endl;
	}
	else if(vertikal()){
		cout<<"vertikal"<<endl;
	}
	else if(horizontal()){
		cout<<"horisontal"<<endl;
	}
	else if(kanan()){
		cout<<"diagonal kanan bawah"<<endl;
	}
	else if(kiri()){
		cout<<"diagonal kiri bawah"<<endl;
	}
	else{
		cout<<"tidak identik"<<endl;
	}
	return 0;
}