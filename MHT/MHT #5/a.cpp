#include <iostream>
using namespace std;

int n,x;
string s;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		x=s.length();
		if(x>10){
			cout<<s[0]<<x-2<<s[x-1]<<endl;;
		}
		else{
			cout<<s<<endl;
		}
	}
	return 0;
}
