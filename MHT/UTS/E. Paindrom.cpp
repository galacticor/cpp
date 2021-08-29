#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i%4==1){
			cout<<"a";
		}
		if(i%4==2){
			cout<<"a";
		}
		if(i%4==0){
		cout<<"b";
		}
		if(i%4==3){
			cout<<"b";
		}
	}
	cout<<endl;
	return 0;
}