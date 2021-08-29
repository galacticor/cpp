#include <iostream>
using namespace std;

int n,x,maks,a,b,c;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(i%3==1){
			a=a+x;
		}
		else if(i%3==2){
			b=b+x;
		}
		else if(i%3==0){
			c=c+x;
		}
	}
	maks=a;
	if(b>maks){
		maks=b;
	}
	if(c>maks){
		maks=c;
	}
	if(maks==a){
		cout<<"chest"<<endl;
	}
	else if(maks==b){
		cout<<"biceps"<<endl;
	}
	else if(maks==c){
		cout<<"back"<<endl;
	}
	return 0;
}
