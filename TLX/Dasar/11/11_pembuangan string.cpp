#include <iostream>
#include <cstring>
using namespace std;

string s,s2;
int a,b;

int main(){
	cin>>s>>s2;
	a=s2.length();
	while(s.find(s2)!=-1){
		size_t x=s.find(s2);
		s.erase(x,a);
	}
	cout<<s<<endl;
	return 0;
}
