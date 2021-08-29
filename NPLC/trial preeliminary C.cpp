#include <bits/stdc++.h>
using namespace std;

int xa,xb,ya,yb,res;

int main(){
	cin>>xa>>ya;
	cin>>xb>>yb;
	res=sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
	cout<<res<<endl;
	return 0;
}