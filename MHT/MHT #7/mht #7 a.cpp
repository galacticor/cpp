#include <iostream>
#include <algorithm>
using namespace std;

int c;
long long t,n,m,o,a[10000010];

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>o;
		c=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(a[1]<o){
			c=-1;
		}
		else {
			for(int k=1;k<=n;k++){
				if(a[k]>=o){
					c+=1;
				}
			}
		}
		if(c>=m){
			cout<<m<<endl;
		}
		else cout<<c<<endl;
	}
	return 0;
}

