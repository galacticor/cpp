#include <bits/stdc++.h>
using namespace std;

long long a,b,c,d,at,bw,ans;

long long gcd(long long x, long long y){
	if(y==0){
		return x;
	}
	else{
		return gcd(y,x%y);
	}
}

int main(){
	cin>>a>>b>>c>>d;
	at=a*d + b*c;
	bw=b*d;
	if(at>bw){
		ans=gcd(at,bw);
	}
	else{
		ans=gcd(bw,at);
	}
	cout<<at/ans<<" "<<bw/ans<<endl;
}