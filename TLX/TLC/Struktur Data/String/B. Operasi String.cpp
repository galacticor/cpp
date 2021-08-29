#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4;
int x,y;

int main(){
	cin>>s1>>s2>>s3>>s4;
	x=s1.find(s2);
	s1.erase(x,s2.length());
	y=s1.find(s3);
	y=y+s3.length();
	s1.insert(y,s4);
	cout<<s1<<endl;
	return 0;

}