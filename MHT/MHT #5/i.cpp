#include <iostream>
using namespace std;

string s[100010],x,y;
int n,x1,x2;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		x=s[1];
		
		if(s[i]==x){
			x1++;
		}
		else{
			y=s[i];
			x2++;
		}
	}
	if(x1>x2){
		cout<<x<<endl;
	}
	else{
		cout<<y<<endl;
	}
	return 0;
}
