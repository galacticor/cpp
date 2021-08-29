#include <iostream>
using namespace std;

int n,p,q,x[1000010],a,b;
string s;

int main(){
	cin>>n;
	cin>>p;
	s="I become the guy.";
	for(int i=1;i<=p;i++){
		cin>>a;
		x[a]=1;
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>b;
		x[b]=1;
	}
	for(int i=1;i<=n;i++){
		if(x[i]!=1){
			s="Oh, my keyboard!";
		}
	}
	cout<<s<<endl;
	return 0;
}
