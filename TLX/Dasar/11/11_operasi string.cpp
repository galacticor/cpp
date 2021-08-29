#include <iostream>
#include <cstring>
using namespace std;

string s1,s2,s3,s4;

int main(){
	cin>>s1>>s2>>s3>>s4;
	int b=s2.length();
	while(s1.find(s2)!=-1){
		size_t x=s1.find(s2);
		s1.erase(x,b);
	}
	size_t a=s1.find(s3);
	int y=a+s3.length();
	s1.insert(y,s4);
	cout<<s1<<endl;
}
