#include <iostream>
using namespace std;

int n,a,b,count;
int arr1[100010],arr2[100010];

int main(){
	cin>>n;
	for(int k=0;k<100010;k++){
		arr2[k]=0;
	}
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int j=0;j<n;j++){
		arr2[arr1[j]]++;
	}
	for(int k=0;k<100010;k++){
		
	}
}
