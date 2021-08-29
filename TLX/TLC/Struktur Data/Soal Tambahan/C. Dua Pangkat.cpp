#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,n;
	n=1;
	cin>>x;
	while(n<x){
		n=n*2;
	}
	if(x==n){
		cout<<"TRUE"<<endl;
	}
	else{
		cout<<"FALSE"<<endl;
	}
	return 0;

}