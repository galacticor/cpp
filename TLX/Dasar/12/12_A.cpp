#include <iostream>
#include <stdlib.h>
using namespace std;

int n,x,a[100010],temp,res;

int main(){
	cin>>n>>x;
	int min=9999999;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		temp=abs(x-a[i]);
		if(temp<min){
			min=temp;
			res=a[i];
		}
		else if(min==temp){
			if(a[i]<res){
				res=a[i];
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
