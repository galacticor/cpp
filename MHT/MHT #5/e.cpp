#include <iostream>
using namespace std;

string s;
char c;
int x,x1,x2,x3;

int main(){
	cin>>s;
	x=s.length();
	if(x==1){
		cout<<s<<endl;
	}
	else{
		for(int i=0;i<=x-1;i+=2){
			c=s[i];
			if(c=='3'){
				x3++;
			}
			if(c=='2'){
				x2++;
			}
			if(c=='1'){
				x1++;
			}
		}
		if(x1>0){
			cout<<"1";
			x1--;
		}
		else if(x2>0){
			cout<<"2";
			x2--;
		}
		else if(x3>0){
			cout<<"3";
			x3--;
		}
		for(int i=1;i<=x1;i++){
			cout<<"+1";
		}
		for(int i=1;i<=x2;i++){
			cout<<"+2";
		}
		for(int i=1;i<=x3;i++){
			cout<<"+3";
		}
	}
		
	cout<<endl;
}
