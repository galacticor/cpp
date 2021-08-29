#include <bits/stdc++.h>
using namespace std;

int a,b,k,x,temp,res;

int funct(int x,int k){
	if(k<=1){
		return abs(a*x+b);
	}
	else{
		k--;
		temp=abs(a*x+b);
		return funct(temp,k);
	}
}

int main(){
	cin>>a>>b>>k>>x;
	res=funct(x,k);
	cout<<res<<endl;
	return 0;
}
