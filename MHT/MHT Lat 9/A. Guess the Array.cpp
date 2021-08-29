#include <bits/stdc++.h>
using namespace std;

int z,a,b,c,nilai[10010],n;

void ans(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>z;
}

int main(){
	cin>>n;
	ans(1,2);
	a=z;
	ans(2,3);
	b=z;
	ans(1,3);
	c=z;
	nilai[1]=(a+b+c)/2-b;
	nilai[2]=(a+b+c)/2-c;
	nilai[3]=(a+b+c)/2-a;
	for(int i=4;i<=n;i++){
		ans(1,i);
		nilai[i]=z-nilai[1];
	}
	cout<<"!";
	for(int i=1;i<=n;i++){
		cout<<" "<<nilai[i];
	}
	cout<<endl;
	return 0;
}