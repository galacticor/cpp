#include <iostream>
using namespace std;

int n,k,l,c,d,p,nl,np;
int x,y,z;

int main(){
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	x=k*l/nl;
	y=c*d;
	z=p/np;
	int min=x/n;
	if(y/n<min){
		min=y/n;
	}
	if(z/n<min){
		min=z/n;
	}
	cout<<min<<endl;
}
