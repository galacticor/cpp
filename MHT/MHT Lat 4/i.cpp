#include <iostream>
using namespace std;

int n,a[100010],x[100010],y[100010],xm,x0,xp,z;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0){
			xm++;
			x[xm]=a[i];
		}
		if(a[i]==0){
			x0++;
		}
		if(a[i]>0){
			xp++;
			y[xp]=a[i];
		}
	}
	if(xp==0){
		xp=2;
		y[1]=x[xm];
		y[2]=x[xm-1];
		xm-=2;
	}
	if(xm%2==0){
		z=x[xm];
		xm--;
		x0++;
	}
	cout<<xm;
	for(int i=1;i<=xm;i++){
		cout<<" "<<x[i];
	}
	cout<<endl;
	
	cout<<xp;
	for(int i=1;i<=xp;i++){
		cout<<" "<<y[i];
	}
	cout<<endl;
	
	if(z!=0){
		cout<<x0;
		for(int i=1;i<=x0-1;i++){
			cout<<" "<<"0";
		}
		cout<<" "<<z<<endl;
	}
	else{
		cout<<x0;
		for(int i=1;i<=x0;i++){
			cout<<" "<<"0";
		}
	}
	
	return 0;
}
