#include <iostream>
using namespace std;

int n,k,res,temp;

int main(){
	cin>>n>>k;
	temp=n/k;
	res=n;
	while(temp>0){
		res++;
		temp--;
		if(res%k==0){
			temp++;
		}
	}
	cout<<res<<endl;
	return 0;
	
}
