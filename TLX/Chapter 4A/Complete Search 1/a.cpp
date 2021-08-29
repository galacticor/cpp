#include <iostream>
using namespace std;

int n,tukar;

int f(int x){
	if(x<12){
		return x;
	}
	else{
		tukar=f(x/2)+f(x/3)+f(x/4);
		if(tukar>x){
			return tukar;
		}
		else{
			return x;
		}
	} 
}

int main(){
	cin>>n;
	cout<<f(n)<<endl;\
	return 0;
}