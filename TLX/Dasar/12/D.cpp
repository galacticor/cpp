#include <iostream>
using namespace std;

long long n,a[100000010],q,x,y,ans,ans1,res,c,b;

void binser(long long x){
	int low=1,hi=n,mid;
	while (low<=hi){
		mid=(low+hi)/2;
		if(a[mid]>x){
			ans=mid;
			hi=mid-1;
		}
		else{
			low=mid+1;
		}
	}
}

void binser1(long long y){
	int low=1,hi=n,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		if(a[mid]<=y){
			ans1=mid;					
			low=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>c>>b;
		ans=-1;
		ans1=-1;
		binser(c);
		binser1(b);
		
		if(ans<1 || ans1<1){
			res=0;
		}
		else{
			if(ans1==ans){
				res=1;
			}
			else{
				res=ans1-ans+1;
			}
		}
		
		cout<<res<<endl;
	}
	return 0;
}
