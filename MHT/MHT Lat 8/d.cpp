#include <iostream>
using namespace std;

long long x,m,a,j,b,sum,temp;
long long check(long long a,long long x){
	if(a/x>0){
		sum=a/x+check(a,x*5);
	}
	else{
		return 0;
	}
	return sum;
}

int main(){
	cin>>m;
	a=0;
	j=check(a,5);
	while(j<m){
		a+=5;
		j=check(a,5);
	}
	if(j>m){
		cout<<"0"<<endl;
	}
	else if(j==m){
		cout<<"5"<<endl;
		for(int i=0;i<=4;i++){
			cout<<i+a;
			if(i<4){
				cout<<" ";
			}
			else{
				cout<<endl;
			}
		}
	}
	return 0;
}