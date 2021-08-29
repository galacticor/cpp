#include <bits/stdc++.h>
using namespace std;

int n,k,d,mem[110],mem1[110],ans;

int f(int x){
	if(x==0){
		return 1;
	}
	else if(mem[x]!=0){
		return mem[x];
	}
	else{
		for(int i=1;i<=k;i++){
			if(x>=i){
				mem[x]=(mem[x]+f(x-i))%1000000007;
			}
		}
	}
	return mem[x];
}

int f1(int x){
	if(x==0){
		return 1;
	}
	else if(mem1[x]!=0){
		return mem1[x];
	}
	else{
		for(int i=1;i<=d-1;i++){
			if(x>=i){
				mem1[x]=(mem1[x]+f1(x-i))%1000000007;
			}
		}
		return mem1[x];
	}

}

int main(){
	cin>>n>>k>>d;
	ans=f(n)-f1(n);
	if(ans<0){
		ans+=1000000007;
	}
	cout<<ans<<endl;
	return 0;
}