#include <iostream>
using namespace std;

int x,y;
int main(){
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		if(i%2==0){
			for(int j=1;j<=y;j++){
			if(j%2==0){
				cout<<"#";
			}
			else {
				cout<<"*";
			}
			}
		}
		else{
			for(int j=1;j<=y;j++){
			if(j%2==0){
				cout<<"*";
			}
			else {
				cout<<"#";
			}
		}
		}
		cout<<endl;
	}
	return 0;
}
