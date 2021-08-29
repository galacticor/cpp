#include <bits/stdc++.h>
using namespace std;

long long l1,r1,l2,r2,k,res;

int main(){
	cin>>l1>>r1>>l2>>r2>>k;
	if((r1>=l2) && !(l2<r1)){
		if(k>=l2 && k<=r1){
			res=r1-l2+1-1;
		}
		else{
			res=r1-l2+1;
		}
		
	}
	else if((r2>=l1) && !(r1<l2)){
		if(k>=l1 && k<=r2){
			res=r2-l1+1-1;
		}
		else{
			res=r2-l1+1;
		}
	}
	
	if((l1<=l2) && (r2<=r1)){
		if((k>=l2) && (k<=r2)){
			res=r2-l2+1-1;
		}
		else{
			res=r2-l2+1;
		}
	}
	else if((l2<=l1) && (r1<=r2)){
		if((k>=l1) && (k<=r1)){
			res=r1-l1+1-1;
		}
		else{
			res=r1-l1+1;
		}
	}
	cout<<res<<endl;
}