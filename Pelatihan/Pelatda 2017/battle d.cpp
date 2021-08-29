#include <iostream>
using namespace std;

int n,a,t,b,maks;
int ways[100010];

int main(){
	cin>>t;
	n=t+1;
	maks=0;
	for (int i=2;i<=n;i++){
		ways[i]=1;
		for(int j=2;j<i;j++){
			if(i%j==0){
				ways[i]=ways[j]+1;
			} 
		}
		for(int j=2;j<=n;j++){
			if(ways[j]>maks){
				maks=ways[j];
			}
		}
	}
	cout<<maks<<endl;
	for(int i=2;i<=n;i++){
		cout<<ways[i]<<" ";
	}
	return 0;
}
