#include <bits/stdc++.h>
using namespace std;

int a[100010],n,j;

void binary(int x){
	if(x==1){
		a[j]++;
	}
	else{
		a[j]=x%2;
		x=x/2;
		j++;
		binary(x);
	}
}

int main(){
	cin>>n;
	j=1;
	binary(n);
	for(int i=n;i>=1;i--){
		if(a[i]>0){
			cout<<i<<" ";
		}
		
	}
	cout<<endl;
	return 0;
}