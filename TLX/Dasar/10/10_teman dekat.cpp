#include <iostream>
#include <stdlib.h> 
using namespace std;

void deket(int )
int n,d,x[1010],y[1010],t[1010][1010],a,b,maks;
long long minimum;

int main(){
	cin>>n>>d;
	maks=0;
	minimum=10000000;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int p,q=1;
			a=abs(x[j]-x[i]);
			b=abs(y[j]-y[i]);
			for(int k=1;k<=d;k++){
				p=p*a;
				q=q*b;
			}
			t[i][j]=p+q;
			if(t[i][j]>maks){
				maks=t[i][j];
			}
			if(t[i][j]<minimum){
				minimum=t[i][j];
			}
		}
	}
	cout<<minimum<<' '<<maks<<endl;
	return 0;
}
