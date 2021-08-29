#include <bits/stdc++.h>
using namespace std;

int n,a[100010],sum1,sum2,num1,num2;
bool p;

int main(){
	cin>>n;
	p=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			num1=a[1];
		}
		if(a[i]==num1){
			sum1++;
		}
		else if(!p || a[i]==num2){
			num2=a[i];
			p=true;
			sum2++;
		}
	}
	if(sum1==sum2 && n==sum1+sum2){
		cout<<"YES"<<endl<<num1<<" "<<num2<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}