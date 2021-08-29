#include <bits/stdc++.h>
using namespace std;

int n,a,res,odd,even;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a%2==0){
			even++;
		}
		else{
			odd++;
		}
	}
	if(odd==1){
		res=1;
	}
	else if(odd>1){
		res=((odd*(odd-1))/2) * even;
	}
	cout<<res<<endl;
	return 0;
}