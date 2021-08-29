#include <iostream>
#include <cstring>
using namespace std;

string s,res;
int x,a,b,y;


int main(){
	cin>>s;
	string temp=s,temp1=s;
	res="NO";
	x=s.find("AB");
	y=s.find("BA");
	if(x!=-1){
		temp.erase(x,3);
		if(temp.length()!=0){
			a=temp.find("BA");
			if(a!=-1){
				res="YES";
			}
		}
		
	}
	if(y!=-1){
		temp1.erase(y,3);
		if(temp1.length()!=0){
			b=temp1.find("AB");
			if(b!=-1){
				res="YES";
			}
		}
		
	}
	cout<<res<<endl;
	return 0;
}
