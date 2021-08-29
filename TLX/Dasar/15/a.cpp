#include <bits/stdc++.h>
using namespace std;

int n;
void gunung(int x){
	if(x==1){
		cout<<"*"<<endl;
		return;
	}
	else{
		gunung(x-1);
		for(int i=1;i<=x;i++){
			cout<<"*";
		}
		cout<<endl;
		gunung(x-1);
	}
}

int main(){
	cin>>n;
	gunung(n);
	return 0;
}
