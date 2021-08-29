#include <bits/stdc++.h>
using namespace std;

string s;
int k,a[10010],sum,res;

int main(){
	cin>>s>>k;
	for(int i=0;i<=s.length()-1;i++){
		a[s[i]]++;
	}
	for(int i=0;i<=1000;i++){
		if(a[i]>0){
			sum++;
		}
	}
	if(sum<k){
		res=k-sum;
	}
	if(k>s.length()){
		cout<<"impossible"<<endl;
	}
	else{
		cout<<res<<endl;
	}
	return 0;
}