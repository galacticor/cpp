#include <iostream>
using namespace std;

int a,n,k,p[10000010],temp,x;

int main(){
	cin>>a>>n>>k;
	n++;
	for(int i=1;i<=k;i++){
		cout<<a%n<<" ";
		a=a/n;
	}
	cout<<endl;
	return 0;
}
