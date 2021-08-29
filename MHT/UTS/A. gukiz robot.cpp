#include <bits/stdc++.h>
using namespace std;

int a,b,x1,x2,y1,y2;

int main(){
	cin>>x1>>y1>>x2>>y2;
	a=abs(x1-x2);
	b=abs(y1-y2);
	if(a>b){
		cout<<a<<endl;
	}
	else{
		cout<<b<<endl;
	}
	return 0;
}