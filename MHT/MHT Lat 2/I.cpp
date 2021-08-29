#include<iostream>
using namespace std;
int n, m;
int main(){
	cin>>n>>m;
	if(n>m){
		if(n>2*m){
			cout<<m<<endl;
		}else cout<<(n+m)/3<<endl;
	}else if(n<m){
		if(2*n<m){
			cout<<n<<endl;
		}else cout<<(n+m)/3<<endl;
	}else{
		cout<<(n+m)/3<<endl;
	}
}
