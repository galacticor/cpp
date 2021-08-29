#include <bits/stdc++.h>
using namespace std;

int n,a[100010],k;
bool p[100010],q;

void permutasi(int deep){
	if(deep>k){
		for(int i=1;i<=k;i++){
			
			cout<<a[i];
			if(i<k){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	else{
		for(int i=a[deep-1];i<=n;i++){
			if(!p[i]){
				p[i]=true;
				a[deep]=i;
				permutasi(deep+1);
				p[i]=false;
			}
		}
	}
}

int main(){
	cin>>n>>k;
	a[0]=1;
	permutasi(1);
	return 0;
}