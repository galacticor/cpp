#include <iostream>
using namespace std;

int a,b,c,d,res;

int main(){
	cin>>a>>b>>c>>d;
	if(b>c){
		if(a<c){
			if(b<d){
				res=b-c;
			}
			else{
				res=d-c;
			}
		}
		else{
			if(d<b){
				res=d-a;
			}
			else{
				res=b-a;
			}
		}
	}
	else{
		res=0;
	}
	if(res<0){
		res=0;
	}
	cout<<res<<endl;
	return 0;
}
