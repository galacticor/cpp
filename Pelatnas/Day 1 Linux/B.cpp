#include "simplification.h"

#include <vector>

int a[100005],n,ans,pans;

void init(int N, std::vector<int> C) {
    for(int i=0;i<(int)C.size();i++){
    	a[i+1]=C[i];
    }
    ans=1;
    for(int i=1;i<N;i++){
		if(a[i]!=a[i+1]){
			ans++;
		}
	}
	n=N;
	pans=ans;
}

int update(int x, int c) {
	if(c==a[x]){
		ans=pans;
	}
	else{
		if(x!=1 && x!=n && a[x]==a[x-1] && a[x]==a[x+1] ){
			ans=pans+2;
		}
		else if(a[x]==a[x-1] && x!=1){
			if(c==a[x+1] && x!=n) ans=pans;
			else ans=pans+1;
		}
		else if(a[x]==a[x+1] && x!=n){
			if(c==a[x-1] && x!=1) ans=pans;
			else ans=pans+1;
		}
		else if(x==n && n==1){
			ans=pans;
		}
		else{
			if(x==n){
				if(c==a[x-1]) ans=pans-1;
				else ans=pans;
			}
			else if(x==1){
				if(c==a[x+1]) ans=pans-1;
				else ans=pans;	
			}
			else{
				if(c==a[x-1] && c==a[x+1]) ans=pans-2;
				else if(c==a[x-1] || c==a[x+1]) ans=pans-1;
				else ans=pans;
			}
		}
	}
	a[x]=c;
	pans=ans;
    return n-ans;
}\