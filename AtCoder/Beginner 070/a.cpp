#include <iostream>
#include <cstring>
using namespace std;

string s,a;
int x;

int main(){
	cin>>s;
	x=s.length();
	a="Yes";
	for(int i=0;i<=x/2-1;i++){
		if(s[i]!=s[x-i-1]){
			a="No";
		}
	}
	cout<<a<<endl;
}
