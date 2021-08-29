#include <iostream>
#include <cstring>
using namespace std;

string s;

int main(){
	cin>>s;
	if(s.find("1111111")!=-1 || s.find("0000000")!=-1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}
