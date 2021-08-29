#include <iostream>
using namespace std;

int n,x[10010],a,b,res;

int main(){
	cin>>n;
	for(int i=1;i<=n-1;i++){
		cin>>x[i];
	}
	cin>>a>>b;
	for(int i=a;i<=b-1;i++){
		res=res+x[i];
	}
	cout<<res<<endl;
}
