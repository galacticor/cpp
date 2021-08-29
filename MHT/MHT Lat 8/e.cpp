#include <bits/stdc++.h>
using namespace std;

int a,b,c;
string memo[100010];
bool memo1[100010];

string kurang(int x){
	if(x==0){
		return "Yes";
	}
	if(x<0){
		return "No";
	}
	else if(memo1[x]==true){
		return memo[x];
	}
	else{
		if(kurang(x-a)=="No"){
			memo[x]=kurang(x-b);
		}
		else{
			memo[x]=kurang(x-a);
		}
	}
	memo1[x]=true;
	return memo[x];
}

int main(){
	cin>>a>>b>>c;
	cout<<kurang(c)<<endl;
	return 0;
}