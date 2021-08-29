#include <iostream>
using namespace std;

int n,a[100010];
bool p,q,t

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	p=true;
	q=true;
	t=true;
	
	if(a[2]<a[1]){
		p=false;
	}
	if(a[2]==a[1]){
		q=false;
	}
	
		int j=3;
		while(j<=n){
			if(p && q){
				if(a[j]>a[j-1]){
					j++;
				}
				else if(a[j]==a[j-1]){
					j++;
					q=false;
				}
				else{
					p=false;
				}
			}
			else if(p){
				if(a[j]==a[j-1]){
					j++;
				}
				else if(a[j]<a[j-1]){
					p=false;
				}
				else{
					t=false;
				}
			}
			else{
				if(a[j]<a[j-1]){
					j++;
					p=false;
				}
				else{
					t=false;
				}
			}
			if(t==false){
				break;
			}
		}
	if(n==1){
		t=true;
	}
	
	if(t){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
