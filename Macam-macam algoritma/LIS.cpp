#include <bits/stdc++.h>
using namespace std;

int a[100010],k,l[100010],res,t,b;

void lis(int x){
	for(int i=1;i<x;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j] && l[i]<l[j]+1){
				l[i]=l[j]+1;
			}
		}
	}
}

int main(){
    cin>>t;
    for(int z=1;z<=t;z++){
	cin>>k;
	res=0;
	for(int y=0;y<k;y++){
		l[y]=1;
	}
	for(int y=0;y<k;y++){
            	cin>>a[y];
	}
	lis(k);
    	for(int i=0;i<k;i++){
    		res=max(res,l[i]);
    	}
    	cout<<res<<endl;
    }
	
	return 0;
}