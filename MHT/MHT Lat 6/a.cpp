#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int a[10010],n;
double l,diff;
double x,z,maks,y;

int main(){
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	x=a[1];
	z=l-a[n];
	for(int i=2;i<=n;i++){
		diff=a[i]-a[i-1];
		if(diff>maks){
			maks=diff;
		}
	}
	y=maks/2;
	cout<<fixed<<setprecision(10);
	if(x>=y && x>=z){
		cout<<x;
	}
	else if(z>=y && z>=x){
		cout<<z;
	}
	else if(y>=x && y>=z){
		cout<<y;
	}
	cout<<endl;
	return 0;
}