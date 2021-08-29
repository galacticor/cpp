#include <iostream>
using namespace std;

long long n,a[100010],x1,x2,y1,y2,maks,mins;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i!=1 && i!=n){
			x1=a[i+1]-a[i];
			x2=a[i]-a[i-1];
			y1=a[i]-a[1];
			y2=a[n]-a[i];
			if(x1>x2){
				mins=x2;
			}
			else{
				mins=x1;
			}
			
			if(y1>y2){
				maks=y1;
			}
			else{
				maks=y2;
			}
		}
		else if(i==1){
			maks=a[n]-a[i];
			mins=a[i+1]-a[i];
		}
		else if(i==n){
			maks=a[i]-a[1];
			mins=a[i]-a[i-1];
		}
		
		cout<<mins<<" "<<maks<<endl;
	}
	return 0;
}
