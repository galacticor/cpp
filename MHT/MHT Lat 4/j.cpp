#include <iostream>
using namespace std;

int n,maks,mak,a[100010],res;

int main(){
	cin>>n;
	maks=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			if(a[i]>maks){
				maks=a[i];
				mak=i;
			}
		}
		
		
	}
	if(a[1]>maks){
		res=0;
	}
	else{
		while(a[1]<=a[mak]){
			a[1]++;
			maks--;
			a[mak]--;
			for(int i=2;i<=n;i++){
				if(a[i]>maks){
					maks=a[i];
					mak=i;
				}
			}
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
