#include <iostream>
#include <cstring>
using namespace std;

string s;
int a,x;

int main(){
	cin>>s>>a;
	if(1<=a<=25){
		for(int i=0;i<s.length();i++){
			x=s[i]+a;
			if(x>122){
				x=x-26;
			}
			s[i]=x;
		}
		cout<<s<<endl;
		return 0;
	}
}
