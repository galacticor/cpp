#include <iostream>
using namespace std;

long long a,b,c,d,res,k;

int main(){
	cin>>a>>b>>c>>d>>k;
	if(b>=c){
		if(a<c){
			if(b<d){
				if(k>=c && k<=b){
					res=b-c+1-1;
				}
				else{
					res=b-c+1;
				}
				
			}
			else{
				if(k>=c && k<=d){
					res=d-c+1-1;
				}
				else{
					res=d-c+1;
				}
			}
		}
		else{
			if(d<b){
				if(k>=a && k<=d){
					res=d-a;
				}
				else{
					res=d-a+1;
				}
				
			}
			else{
				if(k>=a && k<=b){
					res=b-a;
				}
				else{
					res=b-a+1;
				}
				
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