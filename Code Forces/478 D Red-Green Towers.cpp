#include <bits/stdc++.h>
using namespace std;

int a,b,n,k,sum;

void f(int x,int y,int z){
	if(x<0 || y<0){
		return;
	}
	else if(z<1){
		sum++;
		sum%=1000000007;
	}
	else{
		f(x-z,y,z-1);
		f(x,y-z,z-1);
	}
}

int main(){
	cin>>a>>b;
	while(n<=a+b){
		k++;
		n+=k;
	}
	f(a,b,k-1);
	for(int i=1;i*(i+1)/2<=a+b;i++){
		
	}
	cout<<sum<<endl;
	return 0;


}