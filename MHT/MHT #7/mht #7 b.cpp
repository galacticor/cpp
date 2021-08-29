#include <iostream>
#include <algorithm>
using namespace std;

int n,m,x,y,p;
int a[1000010];

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		}
	cin>>m;
	for(int j=1;j<=m;j++){
		cin>>y;
		int k=1;
		while (y>0){
			y=y-a[k];
			if(y<=0){
				cout<<k<<endl;
			}
			else k++;	
			}
		}
		return 0;	
	}
