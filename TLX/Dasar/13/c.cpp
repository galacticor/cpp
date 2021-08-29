#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int n;
float median,x[1000010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1, x+n+1);
	if(n%2==0){
		cout<<fixed<<setprecision(1);
		cout<<(x[n/2]+x[n/2 + 1])/2<<endl;
	}
	else{
		cout<<x[n/2 +1]<<".0"<<endl;
	}
	
}
