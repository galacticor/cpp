#include <bits/stdc++.h>
using namespace std;

int n,a[100010],b[100010],sum;
bool p;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	while(!p){
		p=true;
		for(int i=1;i<=n-1;i++){
			if(a[i+1]<a[i]){
				swap(a[i+1],a[i]);	
				p=false;
				sum++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;


}