#include <bits/stdc++.h>
using namespace std;

int n,a[100010];
bool p[100010],q;

void permutasi(int deep){
	if(deep>n){
		q=false;
		for(int i=2;i<=n;i++){
			if(i%2==0){
				if(a[2]<a[1] && a[2]<a[3]){
					if(a[i]>a[i-1] || a[i]>a[i+1]){
						q=true;
					}	
				}
				else{
					if(a[i]<a[i-1] || a[i]<a[i+1]){
						q=true;
					}
				}
			}
			
		}
		if(!q){
			for(int i=1;i<=n;i++){
				cout<<a[i];
			}
			cout<<endl;
		}	
	}
	else{
		for(int i=1;i<=n;i++){
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
	cin>>n;
	int a[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	do{
		q=false;
		for(int i=2;i<=n;i++){
			if(i%2==0){
				if(a[2]<a[1] && a[2]<a[3]){
					if(a[i]>a[i-1] || a[i]>a[i+1]){
						q=true;
					}	
				}
				else{
					if(a[i]<a[i-1] || a[i]<a[i+1]){
						q=true;
					}
				}
			}
			
		}
		if(!q){
			for(int i=1;i<=n;i++){
				cout<<a[i];
			}
			cout<<endl;
		}	
	}while(next_permutation(a+1,a+n+1));
	return 0;
}