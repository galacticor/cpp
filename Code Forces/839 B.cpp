#include <iostream>
using namespace std;

int n,k,x,a,sum;
string s;

int main(){
	cin>>n>>k;
	s="YES";
	x=8*n;
	if(k>x/2){
		s="NO";
		for(int i=1;i<=k;i++){
			cin>>a;
		}
	}
	else if(k<x/2){
		for(int i=1;i<=k;i++){
			cin>>a;
			if(a%2==0){
				x=x-a;
			}
			else{
				x=x-a-1;
			}	
		}
		if(x<0){
			s="NO";
		}
	}
	else{
		for(int i=1;i<=k;i++){
			cin>>a;
			if(a==1){
				sum++;
			}
			if(a>2){
				s="NO";
			}
		}
		if(sum<n){
			s="NO";
		}
	}
	cout<<s<<endl;
}
