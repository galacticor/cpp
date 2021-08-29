#include <iostream>
#include <cstring>
using namespace std;

string s,res;
int a,b,c,d;

int main(){
	cin>>s;
	res="NO";
	a=s.find("h");
	b=s.find("e");
	c=s.find("l");
	d=s.find("o");
	if(a!=-1 && b!=-1 && c!=-1 && d!=-1){
		s.erase(0,a+1);
		b=s.find("e");
		if(b!=-1){
			s.erase(0,b+1);
			c=s.find("l");
			if(c!=-1){
				s.erase(0,c+1);
				c=s.find("l");
				if(c!=-1){
					s.erase(0,c+1);
					d=s.find("o");
					if(d!=-1){
						res="YES";
					}
				}
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
