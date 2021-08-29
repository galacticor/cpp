#include <iostream>
#include <stdlib.h> 
using namespace std;

int n,d,x[1010],y[1010];

void dekat(int n,int d){
	int maks,minimum,a,b,g,h;
	maks=-1;
	minimum=9999999;
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			int p=1,q=1;
			int t;
			g=abs(x[i]-x[j]);
			h=abs(y[i]-y[j]);
			for(int k=1;k<=d;k++){	
				p=p*g;
				q=q*h;
			}
			t=p+q;
			if(t>=maks){
				maks=t;
			}
			if(t<=minimum){
				minimum=t;
			}
		}
	}
	cout<<minimum<<' '<<maks<<endl;
}

int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	dekat(n,d);
	return 0;
}
