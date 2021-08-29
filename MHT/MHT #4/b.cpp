#include <iostream>
using namespace std;

int t,j,k,l,a[100010],x[100010],y[100010],z[100010],x1,x2,x3,mins;

int main(){
	cin>>t;
	j=1;
	k=1;
	l=1;
	for(int i=1;i<=t;i++){
		cin>>a[i];
		if(a[i]==1){
			x1++;
			x[j]=i;
			j++;
		}
		if(a[i]==2){
			x2++;
			y[k]=i;
			k++;
		}
		if(a[i]==3){
			x3++;
			z[l]=i;
			l++;
		}
	}
	mins=x1;
	if(x2<mins){
		mins=x2;
	}
	if(x3<mins){
		mins=x3;
	}
	j=1;
	k=1;
	l=1;
	cout<<mins<<endl;
	for(int i=1;i<=mins;i++){
		cout<<x[j]<<" "<<y[j]<<" "<<z[j]<<endl;
		j++;
		k++;
		l++;
	}
	return 0;
}
