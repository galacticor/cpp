#include <bits/stdc++.h>
using namespace std;

long long a,b,c,n,ans,temp;

long long fe(int x, int y){
	if(y==1){
		return x;
	}
	else{
		if(y%2==1){
			temp=fe(x,y-1)*x;
			return (temp)%n;
		}
		else{
			temp=fe(x,y/2);
			return (temp*temp)%n;
		}
	}
}

int main(){
	cin>>a>>b>>c>>n;
	ans=a;
	for(int i=1;i<=c;i++){
		ans=fe(ans,b)%n;
	}
	cout<<ans+1<<endl;
	return 0;

}