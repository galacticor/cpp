#include <iostream>
using namespace std;

int n,res,a;
long long memo[1010],ans;

int star(int x){
	if(x==0){
		return 1;
	}
	else if(x==1){
		return 1;
	}
	else if(x==2){
		return 2;
	}
	else if(x==3){
		return 4;
	}
	else if(memo[x]!=0){
		return memo[x];
	}
	memo[x]=star(x-1)+star(x-2)+star(x-3);
	return memo[x];
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cout<<star(a)<<endl;
	}
	return 0;
}