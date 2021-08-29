#include <iostream>
using namespace std;

int n,x,cri,pol,res;

int main(){
	cin>>n;
	
	res=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		
		if(x==-1){
			cri++;
		}
		else {
			pol=pol+x;;
		}
		if(cri>pol){
			res++;
			cri=0;
			pol=0;
		}
		
	}
	cout<<res<<endl;
}
