#include <bits/stdc++.h>
using namespace std;

int t,n;

string aprima(int x){
	int sum=0;
	for(int i=2;i*i<x;i++){
		if(x%i==0){
			sum++;
		}
	}
	if(sum>1){
		return "TIDAK";
	}
	else{
		return "YA";
	}
}

int main(){
	cin>>t;
	for(int co=1;co<=t;co++){
		cin>>n;
		cout<<aprima(n)<<endl;
	}
	return 0;
}